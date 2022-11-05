%{
  #include <stdio.h>
  #include<string.h>
  #include <stdbool.h>
  #include <stdlib.h>
  int yylex();
  int yyerror();
  int line_no = 0;
  bool error_status = false;
  int variable_index=0,label_index=0;
  char* generateVariable();
  char* generateLabel();
  int MAXSIZE = 50;       
  char instack[50][50];
  char outstack[50][50];   
  int topin = 0;
  int topout = 0;
  void pushin();
  void pushout();   
  char* popin();
  char* popout();
  struct Node{
    char vname[50];
    char type[50];
    int addr;
    int size;
  };
  
  struct SNode{
    char vname[50];
    char type[50];
    int addr;
    int size;
    int tab_sz;
    struct Node* tables[50];
  };

  struct TNode{
    int size;
    int struct_table_size;
    struct Node* tables[50];
    struct SNode* struct_tables[50];
  };
  struct TNode *Table_Stack[50];
  struct Node variable[1000];
  struct SNode struct_variable[1000];
  int var_idx = 0;
  int struct_var_idx = 0;
  struct TNode stack_node[50];
  int table_idx = 0;
  int base_address = 0;
  int offset = 1;
  int struct_offset = 1;
  char temp_store[50];
  void init();
  void insert();
  bool typecheckStruct(char* type,char* data);
  bool redeclarationStruct(char* type,char* data);
  bool missingdeclarationStruct(char* data);
  bool typecheck(char* type,char* data);
  bool redeclaration(char* type,char* data);
  bool missingdeclaration(char* data);
  void print_table();
%}

%union{
	char string[100];
}

%token<string> WHILE
%token<string> TRUE
%token<string> FALSE
%token<string> EQ
%token<string> NEQ
%token<string> LOR
%token<string> LAND
%token<string> LTEQ
%token<string> GTEQ
%token<string> LT
%token<string> GT
%token<string> XOR
%token<string> BOR
%token<string> BAND
%token<string> AEQ
%token<string> INC
%token<string> DEC
%token<string> NUM
%token<string> ID
%token<string> IF
%token<string> ELSE
%token<string> STRUCT
%token<string> INT
%token<string> FLOAT
%token<string> POINTER
%token<string> CHAR
%token<string> ARROP
%token<string> ARRCL
%token<string> CRLOP
%token<string> CRLCL

%type<string> E
%type<string> ANY
%type<string> CMP
%type<string> COND
%type<string> ASSIGN
%type<string> AFTER
%type<string> LATER
%type<string> PRE
%type<string> STMT
%type<string> DUMMY
%type<string> VAR_DEC
%type<string> STRUCTDEC
%type<string> INSSTR
%type<string> OPTID
%type<string> TYPE
%type<string> NEXT
%type<string> ARRM
%type<string> B
%type<string> C
%type<string> D

%left '+' '-' 
%left POINTER '/'
%right AEQ
%left LAND LOR
%left LT GT LTEQ GTEQ EQ NEQ
%left ID
%left INC DEC
%right UMINUS
%left '!'
%left XOR BAND BOR


%%

start : {
          init();
        } 
        slst { 
              if(error_status)
              {
                printf("\nSnippet no: %d : ERROR\n",++line_no,variable_index=0,label_index=0);
              }
              else 
              { 
                printf("\nSnippet no: %d : ACCEPTED\n",++line_no,variable_index=0,label_index=0);
              }
              }
               ;

slst :  E slst | E;

BODY : slst | {};

E    : STMT | DUMMY CONTROL ;

DUMMY : {char topp[50]; strcpy(topp,generateLabel()); pushout(topp); printf("%s :\n",topp);}  ;

CONTROL : E1 | E2;

E1   : WHILE '(' COND ')' 
      CRLOP {
              // print_table(Table_Stack[table_idx-1]);
              init();
              // print_table(Table_Stack[table_idx-1]);
              char topp[50];
              strcpy(topp,instack[topin-1]);
              topin=topin-1;
              printf("%s :\n",topp);
          } 

       BODY

      CRLCL {
              char topp[50];
              strcpy(topp,outstack[topout-2]);
              printf("goto %s\n",topp);
              strcpy(topp,outstack[topout-1]);
              topout=topout-2;
              printf("%s :",topp);
              table_idx--;
       } ;
      //  | WHILE '(' COND ')' {char topp[50];  strcpy(topp,instack[topin-1]); topin=topin-1; printf("%s :",topp);} 
      //  slst {char topp[50];  strcpy(topp,outstack[topout-2]);  printf("goto %s\n",topp);}
      //  {char topp[50];  strcpy(topp,outstack[topout-1]); topout=topout-1; printf("%s :",topp);} ;
      //  | WHILE '(' COND ')' ';' {char topp[50];  strcpy(topp,outstack[topout-2]);  printf("goto %s\n",topp);}
      //  {char topp[50];  strcpy(topp,outstack[topout-1]); topout=topout-1; printf("%s :",topp);} ;

E2  : CRLOP {
            init();
          }
          BODY
      CRLCL {table_idx--;};

COND : ANY CMP AFTER {strcpy($$,generateLabel()); printf("if %s %s %s goto %s\n",$1,$2,$3,$$);
                      pushin($$);
                      strcpy($$,generateLabel()); printf("goto %s\n",$$);
                      pushout($$);
                      }
      | ID ASSIGN AFTER {
                        if(missingdeclaration($1))
                        {
                          printf( "error : var '%s' is not declared in the scope\n",$1);
                        }
                        else
                        {
                          strcpy($$,generateLabel()); printf("if %s %s %s goto %s\n",$1,$2,$3,$$);
                          pushin($$);
                          strcpy($$,generateLabel()); printf("goto %s\n",$$);
                          pushout($$);
                        }
                      }
      | ANY {strcpy($$,generateLabel()); printf("if %s != 0 goto %s\n",$1,$$);
              pushin($$);
             strcpy($$,generateLabel()); printf("goto %s\n",$$);
              pushout($$);
           };

STMT : VAR_DEC ';'
     | STRUCTDEC ';'
     | IF       
      '(' 
        COND  {
                init();
                char topp[50];
                strcpy(topp,instack[topin-1]);
                topin=topin-1;
                printf("%s :\n",topp);
              }
      ')'
      CRLOP BODY CRLCL  {
                      char topp[50];
                      strcpy(topp,generateLabel());
                      pushout(topp);
                      printf("goto %s\n",topp);
                    } 
       ELSE  
       
       CRLOP          {
                      char topp[50];
                      strcpy(topp,outstack[topout-2]);
                      strcpy(outstack[topout-2],outstack[topout-1]);
                      topout-=1;
                      printf("%s :\n",topp);
                    }
       BODY CRLCL 
                    {
                      char topp[50];
                      strcpy(topp,outstack[topout-1]);
                      topout=topout-1;
                      printf("%s :\n",topp);
                      table_idx--;
                    }
     | ID ASSIGN AFTER ';' {

                              // print_table();                        
                              if(missingdeclaration($1))
                              {
                                printf( "error : var '%s' is not declared in the scope\n",$1);
                              }
                              else
                              {
                                printf("%s = %s",$$,$3);
                              }     
                           }
     | PRE ';'
     ;


VAR_DEC : TYPE {strcpy(temp_store,$1);} REP ; 
REP     :  REP ',' NEXT      { 
                                  // printf("%s\n",$2);
                                bool check1 = typecheck(temp_store,$3);
                                bool check2 = redeclaration(temp_store,$3);
                                if(check1)
                                {
                                  printf("error : conflicting types for '%s'\n",$3);
                                }
                                else if(check2)
                                {
                                  printf("error : redeclaration of '%s'\n",$3);
                                }
                                else
                                {
                                  strcpy(variable[var_idx].type,temp_store);
                                  strcpy(variable[var_idx].vname,$3);
                                  if(!strcmp(temp_store,"int"))
                                  {
                                    offset*=4;
                                  }
                                  else if(!strcmp(temp_store,"float"))
                                  {
                                    offset*=4;
                                  }
                                  else if(!strcmp(temp_store,"char"))
                                  {
                                    offset*=1;
                                  }
                                  else if(!strcmp(temp_store,"pointer"))
                                  {
                                    offset*=4;
                                  }
                                  else if(!strcmp(temp_store,"struct"))
                                  {
                                    offset*=1;
                                  } 
                                  // printf("%d ",base_address);
                                  printf("0x%04x ", base_address);
                                  variable[var_idx].addr = base_address;
                                  int cur_size = offset;
                                  variable[var_idx++].size = offset;
                                  base_address+=offset;
                                  offset = 1;
                                  insert(&variable[var_idx-1]);
                                  printf("%s ",$3);
                                  printf("%s ",temp_store);
                                  printf("%d\n",cur_size);
                                }
                                // print_table();
                              }
        | REP ',' NEXT ASSIGN ANY  {
                                  bool check1 = typecheck(temp_store,$3);
                                  bool check2 = redeclaration(temp_store,$3);
                                  if(check1)
                                  {
                                    printf("error : conflicting types for '%s'\n",$3);
                                  }
                                  else if(check2)
                                  {
                                    printf("error : redeclaration of '%s'\n",$3);
                                  }
                                  else
                                  {
                                    printf("%s = %s\n",$3,$5);
                                    strcpy(variable[var_idx].type,temp_store);
                                    strcpy(variable[var_idx].vname,$3);
                                    if(!strcmp(temp_store,"int"))
                                    {
                                      offset*=4;
                                    }
                                    else if(!strcmp(temp_store,"float"))
                                    {
                                      offset*=4;
                                    }
                                    else if(!strcmp(temp_store,"char"))
                                    {
                                      offset*=1;
                                    }
                                    else if(!strcmp(temp_store,"pointer"))
                                    {
                                      offset*=4;
                                    } 
                                    else if(!strcmp(temp_store,"struct"))
                                    {
                                      offset*=1;
                                    } 
                                    // printf("%d ",base_address);
                                    printf("0x%04x ", base_address);
                                    variable[var_idx].addr = base_address;
                                    int cur_size = offset;
                                    variable[var_idx++].size = offset;
                                    base_address+=offset;
                                    offset = 1;
                                    insert(&variable[var_idx-1]);
                                    printf("%s ",$3);
                                    printf("%s ",temp_store);
                                    printf("%d\n",cur_size);
                                  }
                               }
          | NEXT  { 
                                  // printf("%s\n",$2);
                                bool check1 = typecheck(temp_store,$1);
                                bool check2 = redeclaration(temp_store,$1);
                                if(check1)
                                {
                                  printf("error : conflicting types for '%s'\n",$1);
                                }
                                else if(check2)
                                {
                                  printf("error : redeclaration of '%s'\n",$1);
                                }
                                else
                                {
                                  strcpy(variable[var_idx].type,temp_store);
                                  strcpy(variable[var_idx].vname,$1);
                                  if(!strcmp(temp_store,"int"))
                                  {
                                    offset*=4;
                                  }
                                  else if(!strcmp(temp_store,"float"))
                                  {
                                    offset*=4;
                                  }
                                  else if(!strcmp(temp_store,"char"))
                                  {
                                    offset*=1;
                                  }
                                  else if(!strcmp(temp_store,"pointer"))
                                  {
                                    offset*=4;
                                  }
                                  else if(!strcmp(temp_store,"struct"))
                                  {
                                    offset*=1;
                                  } 
                                  // printf("%d ",base_address);
                                  printf("0x%04x ", base_address);
                                  variable[var_idx].addr = base_address;
                                  int cur_size = offset;
                                  variable[var_idx++].size = offset;
                                  base_address+=offset;
                                  offset = 1;
                                  insert(&variable[var_idx-1]);
                                  printf("%s ",$1);
                                  printf("%s ",temp_store);
                                  printf("%d\n",cur_size);
                                }
                                // print_table();
                              }
          | NEXT ASSIGN ANY {
                                  bool check1 = typecheck(temp_store,$1);
                                  bool check2 = redeclaration(temp_store,$1);
                                  if(check1)
                                  {
                                    printf("error : conflicting types for '%s'\n",$1);
                                  }
                                  else if(check2)
                                  {
                                    printf("error : redeclaration of '%s'\n",$1);
                                  }
                                  else
                                  {
                                    printf("%s = %s\n",$1,$3);
                                    strcpy(variable[var_idx].type,temp_store);
                                    strcpy(variable[var_idx].vname,$1);
                                    if(!strcmp(temp_store,"int"))
                                    {
                                      offset*=4;
                                    }
                                    else if(!strcmp(temp_store,"float"))
                                    {
                                      offset*=4;
                                    }
                                    else if(!strcmp(temp_store,"char"))
                                    {
                                      offset*=1;
                                    }
                                    else if(!strcmp(temp_store,"pointer"))
                                    {
                                      offset*=4;
                                    } 
                                    else if(!strcmp(temp_store,"struct"))
                                    {
                                      offset*=1;
                                    } 
                                    // printf("%d ",base_address);
                                    printf("0x%04x ", base_address);
                                    variable[var_idx].addr = base_address;
                                    int cur_size = offset;
                                    variable[var_idx++].size = offset;
                                    base_address+=offset;
                                    offset = 1;
                                    insert(&variable[var_idx-1]);
                                    printf("%s ",$1);
                                    printf("%s ",temp_store);
                                    printf("%d\n",cur_size);
                                  }
                               }
              ;

TYPE    : B {strcpy($$,$1);}
        | B PTRDEC {strcpy($$,"pointer");};

B       : INT {strcpy($$,"int");}| FLOAT {strcpy($$,"float");}| CHAR {strcpy($$,"char");};

NEXT    : ID {
                strcpy($$,$1);
             }
          | ARRM;

ARRM    : ID {offset = 1;} C {
                                // if(missingdeclaration($1))
                                // {
                                //   printf( "error : var '%s' is not declared in the scope\n",$1);
                                // }
                                // else
                                // {
                                  strcpy($$,$1);
                                // }
                             } ;

PTRDEC  : POINTER PTRDEC | POINTER;

STRUCTDEC : STRUCT CRLOP  {
                          struct_variable[struct_var_idx].tab_sz = 0;
                          struct_offset = base_address;
                          init();
                        }
              INSSTR
                            
                  CRLCL
            OPTID 
                {
                  // print_table();
                  bool check1 = typecheck($1,$6);
                  bool check2 = redeclaration($1,$6);
                  
                  if(check1)
                  {
                    printf("error : conflicting types for '%s'\n",$6);
                  }
                  else if(check2)
                  {
                    printf("error : redeclaration of '%s'\n",$6);
                  }
                  else
                  {
                    // finding the offset
                    int temp = struct_offset;
                    struct_offset = base_address - struct_offset;
                    offset = struct_offset;
                    base_address = temp;
                    printf("0x%04x ", base_address);
                    strcpy(struct_variable[struct_var_idx].vname,$6);
                    strcpy(struct_variable[struct_var_idx].type,"struct");
                    printf("%s ",$6);
                    printf("%s ",$1);
                    printf("%d\n",offset);
                    struct_variable[struct_var_idx].size = offset;
                    insert_struct(&struct_variable[struct_var_idx]);
                    table_idx--;
                    struct_var_idx++;
                    offset = 1;                
                  }
                }
            ; 

OPTID : ID {
              strcpy($$,$1);
           }| {};

INSSTR : TYPE NEXT  { 
                                  // printf("%s\n",$2);
                                bool check1 = typecheckStruct($1,$2);
                                bool check2 = redeclarationStruct($1,$2);
                                if(check1)
                                {
                                  printf("error : conflicting types for '%s'\n",$2);
                                }
                                else if(check2)
                                {
                                  printf("error : redeclaration of '%s'\n",$2);
                                }
                                else
                                {
                                  strcpy(variable[var_idx].type,$1);
                                  strcpy(variable[var_idx].vname,$2);
                                  if(!strcmp($1,"int"))
                                  {
                                    offset*=4;
                                  }
                                  else if(!strcmp($1,"float"))
                                  {
                                    offset*=4;
                                  }
                                  else if(!strcmp($1,"char"))
                                  {
                                    offset*=1;
                                  }
                                  else if(!strcmp($1,"pointer"))
                                  {
                                    offset*=4;
                                  }
                                  else if(!strcmp($1,"struct"))
                                  {
                                    offset*=1;
                                  } 
                                  // printf("%d ",base_address);
                                  // printf("0x%04x ", base_address);
                                  variable[var_idx].addr = base_address;
                                  int cur_size = offset;
                                  variable[var_idx++].size = offset;
                                  base_address+=offset;
                                  offset = 1;
                                  // strcpy(struct_variable[struct_var_idx].vname,variable[var_idx-1].vname);
                                  // strcpy(struct_variable[struct_var_idx].type,variable[var_idx-1].type);
                                  // struct_variable[struct_var_idx].addr = variable[var_idx-1].addr;
                                  int tab_sz = struct_variable[struct_var_idx].tab_sz;
                                  struct_variable[struct_var_idx].tables[tab_sz] = (&variable[var_idx-1]);
                                  struct_variable[struct_var_idx].tab_sz++;
                                  // printf("%s ",$2);
                                  // printf("%s ",$1);
                                  // printf("%d\n",cur_size);
                                }
                                // print_table();
                              }
                    ';' INSSTR | {/*print_table();*/};

C       : ARROP NUM {offset*=atoi($2);} D;

D       : ARRCL | ARRCL C;

AFTER : AFTER '+' AFTER {
                          strcpy($$,generateVariable());
                          printf("%s = %s + %s\n",$$,$1,$3);
                        }
      | AFTER '-' AFTER {
                          strcpy($$,generateVariable());
                          printf("%s = %s - %s\n",$$,$1,$3);
                        }
      | AFTER XOR AFTER {
                          strcpy($$,generateVariable());
                          printf("%s = %s ^ %s\n",$$,$1,$3);
                        }
      | AFTER BAND AFTER {
                          strcpy($$,generateVariable());
                          printf("%s = %s & %s\n",$$,$1,$3);
                         }
      | AFTER BOR AFTER {
                          strcpy($$,generateVariable());
                          printf("%s = %s | %s\n",$$,$1,$3);
                        }
      | PRE {
              strcpy($$,generateVariable());
              printf("%s = %s\n",$$,$1);
            }
      | LATER ;

LATER : LATER POINTER LATER {
                          strcpy($$,generateVariable());
                          printf("%s = %s * %s\n",$$,$1,$3);
                        }
      | LATER '/' LATER {
                          strcpy($$,generateVariable());
                          printf("%s = %s / %s\n",$$,$1,$3);
                        }
      | ANY ;

PRE   : INC ID {
                if(missingdeclaration($2))
                {
                   printf( "error : var '%s' is not declared in the scope\n",$2);
                }
                else
                {
                  strcpy($$,generateVariable());
                  printf("%s = %s\n",$$,$2);
                  printf("%s = %s + 1\n",$$,$$);
                  printf("%s = %s\n",$2,$$);
                }
               }
      | ID INC {
                if(missingdeclaration($1))
                {
                   printf( "error : var '%s' is not declared in the scope\n",$1);
                }
                else
                {
                  strcpy($$,generateVariable());
                  printf("%s = %s\n",$$,$1);
                  printf("%s = %s + 1\n",$$,$$);
                  printf("%s = %s\n",$1,$$);
                }
               }
      | DEC ID {
                if(missingdeclaration($2))
                {
                   printf( "error : var '%s' is not declared in the scope\n",$2);
                }
                else
                {
                  strcpy($$,generateVariable());
                  printf("%s = %s\n",$$,$2);
                  printf("%s = %s - 1\n",$$,$$);
                  printf("%s = %s\n",$2,$$);
                }
               }
      | ID DEC {
                if(missingdeclaration($1))
                {
                   printf( "error : var '%s' is not declared in the scope\n",$1);
                }
                else
                {
                  strcpy($$,generateVariable());
                  printf("%s = %s\n",$$,$1);
                  printf("%s = %s - 1\n",$$,$$);
                  printf("%s = %s\n",$1,$$);
                }
               }  ;

ANY : NUM {
            strcpy($$,generateVariable());
            printf("%s = %s\n",$$,$1);
          }
    | ID {
            if(missingdeclaration($1))
            {
                printf( "error : var '%s' is not declared in the scope\n",$1);
            }
            else
            {
              strcpy($$,generateVariable());
              printf("%s = %s\n",$$,$1);
            }
         }
    | TRUE {
              strcpy($$,generateVariable());
              printf("%s = %s\n",$$,$1);
           }
    | FALSE {
              strcpy($$,generateVariable());
              printf("%s = %s\n",$$,$1);
            };

CMP : EQ {strcpy($$,$1);}   
    | NEQ {strcpy($$,$1);}
    | LOR {strcpy($$,$1);}  
    | LAND {strcpy($$,$1);}
    | LTEQ {strcpy($$,$1);} 
    | GTEQ {strcpy($$,$1);}
    | LT {strcpy($$,$1);}   
    | GT {strcpy($$,$1);};

ASSIGN : AEQ {strcpy($$,$1);};

%%

void insert(struct Node* entry)
{
  int cur_size = Table_Stack[table_idx-1]->size;
  // printf("cur_size : %d\n",cur_size);
  Table_Stack[table_idx-1]->tables[cur_size] = entry;
  Table_Stack[table_idx-1]->size = Table_Stack[table_idx-1]->size + 1;
  // printf("cur_size : %d\n",Table_Stack[table_idx-1]->size);
}

void insert_struct(struct SNode* entry)
{
  int cur_size = Table_Stack[table_idx-1]->struct_table_size;
  // printf("cur_size : %d\n",cur_size);
  Table_Stack[table_idx-1]->struct_tables[cur_size] = entry;
  Table_Stack[table_idx-1]->struct_table_size = Table_Stack[table_idx-1]->struct_table_size + 1;
  printf("cur_size : %d\n",Table_Stack[table_idx-1]->struct_table_size);
}

void print_table()
{
  printf(" ------------------------------------------------ \n");
  printf("|          CURRENT SYMBOL TABLE                  |\n");
  printf("| ---------------------------------------------- |\n");
  printf("| var_name      type            address   size   |\n");
  int sz = Table_Stack[table_idx-1]->size;
  for(int i=0;i<sz;i++)
  { 
    printf("| ");
    printf("%s\t\t",Table_Stack[table_idx-1]->tables[i]->vname);
    printf("%s\t\t",Table_Stack[table_idx-1]->tables[i]->type);
    printf("%d\t  ",Table_Stack[table_idx-1]->tables[i]->addr);
    printf("%d\t |\n",Table_Stack[table_idx-1]->tables[i]->size);
  }
  printf("\n| struct_name   type            address   size   |\n");
  sz = Table_Stack[table_idx-1]->struct_table_size;
  for(int i=0;i<sz;i++)
  { 
    printf("| ");
    printf("%s\t\t",Table_Stack[table_idx-1]->struct_tables[i]->vname);
    printf("%s\t\t",Table_Stack[table_idx-1]->struct_tables[i]->type);
    printf("%d\t  ",Table_Stack[table_idx-1]->struct_tables[i]->addr);
    printf("%d\t |\n",Table_Stack[table_idx-1]->struct_tables[i]->size);
  }
  printf(" ------------------------------------------------ \n");
}

//---------------- STRUCT CHECKING -------------------------
bool typecheckStruct(char* type,char* data)
{
      int i = struct_var_idx;
      int inner_size = struct_variable[i].tab_sz;
      for(int j=0;j<inner_size;j++)
      {
        if(strcmp(struct_variable[i].tables[j]->type,type) && (!strcmp(struct_variable[i].tables[j]->vname,data)))
        {
          return error_status = true;
        }
      }
    return false;
}

bool redeclarationStruct(char* type,char* data)
{
      int i = struct_var_idx;
      int inner_size = struct_variable[i].tab_sz;
      for(int j=0;j<inner_size;j++)
      {
        if((!strcmp(struct_variable[i].tables[j]->type,type)) && (!strcmp(struct_variable[i].tables[j]->vname,data)))
        {
          return error_status = true;
        }
      }
      return false;
}

bool missingdeclarationStruct(char* data)
{
      int i = struct_var_idx;
      int inner_size = struct_variable[i].tab_sz;
      for(int j=0;j<inner_size;j++)
      {
        if(!strcmp(struct_variable[i].tables[j]->vname,data))
        {
          return false;
        }
      }
    return error_status = true;
}

//----------------------------------------------------------

bool typecheck(char* type,char* data)
{
    for(int i=0;i<table_idx;i++)
    {
      int inner_size = Table_Stack[i]->size;
      for(int j=0;j<inner_size;j++)
      {
        if(strcmp(Table_Stack[i]->tables[j]->type,type) && (!strcmp(Table_Stack[i]->tables[j]->vname,data)))
        {
          return error_status = true;
        }
      }
      inner_size = Table_Stack[i]->struct_table_size;
      for(int j=0;j<inner_size;j++)
      {
        if(strcmp(Table_Stack[i]->struct_tables[j]->type,type) && (!strcmp(Table_Stack[i]->struct_tables[j]->vname,data)))
        {
          return error_status = true;
        }
      }
    }
    return false;
}

bool redeclaration(char* type,char* data)
{
    for(int i=0;i<table_idx;i++)
    {
      int inner_size = Table_Stack[i]->size;
      for(int j=0;j<inner_size;j++)
      {
        if((!strcmp(Table_Stack[i]->tables[j]->type,type)) && (!strcmp(Table_Stack[i]->tables[j]->vname,data)))
        {
          // printf("1. %s\n",Table_Stack[i]->tables[j]->type);
          // printf("2. %s\n",type);
          // printf("3. %s\n",Table_Stack[i]->tables[j]->vname);
          // printf("4. %s\n",data);
          return error_status = true;
        }
      }
      inner_size = Table_Stack[i]->struct_table_size;
      for(int j=0;j<inner_size;j++)
      {
        if((!strcmp(Table_Stack[i]->struct_tables[j]->type,type)) && (!strcmp(Table_Stack[i]->struct_tables[j]->vname,data)))
        {
          printf("128938912389123\n");
          return error_status = true;
        }
      }
    }
    return false;
}

bool missingdeclaration(char* data)
{
    for(int i=0;i<table_idx;i++)
    {
      int inner_size = Table_Stack[i]->size;
      for(int j=0;j<inner_size;j++)
      {
        if(!strcmp(Table_Stack[i]->tables[j]->vname,data))
        {
          return false;
        }
      }
      inner_size = Table_Stack[i]->struct_table_size;
      for(int j=0;j<inner_size;j++)
      {
        if(!strcmp(Table_Stack[i]->struct_tables[j]->vname,data))
        {
          return false;
        }
      }
    }
    return error_status = true;
}

void init()
{
    stack_node[table_idx].size = 0;
    Table_Stack[table_idx] = (&stack_node[table_idx]);
    table_idx++;
}

char* generateVariable()
{
    char *temp=(char *)malloc(sizeof(2*10));
    sprintf(temp,"t%d",variable_index);
    variable_index++;
    return temp;
}

char* generateLabel()
{
    char *temp=(char *)malloc(sizeof(2*10));
    sprintf(temp,"L%d",label_index);
    label_index++;
    return temp;
}

char* popout() {
    
    char data[50];
    strcpy(data,outstack[topout-1]);
    topout = topout - 1;   
    return data;
}

char* popin() {
    
    char data[50];
    strcpy(data,instack[topin-1]);
    topin = topin - 1;   
    return data;
}

void pushin(char* data) {

    strcpy(instack[topin++],data);

}

void pushout(char* data) {

    strcpy(outstack[topout++],data);

}

int yyerror()
{
  printf("\n\nSyntax Error!\n");
  return 0;
}

extern FILE *yyin;

int main(int argc,char* argv[])
{
  if(argc > 1)
  {
    FILE *fp = fopen(argv[1],"r");
    if(fp)
      yyin = fp;
  }
  yyparse();
  return 0;
}
