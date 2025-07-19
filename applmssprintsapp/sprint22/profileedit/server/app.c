#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include<stdbool.h>


#define MAX_BUF_STR  1024 << 2

#define MAX_LEN_DATA 1024 
#define MAX_len_EMAIL  512



typedef struct Data Data  ;
typedef struct String String ;





typedef struct Node Node  ;
typedef struct DNode DNode  ;
struct DNode  {
  
	int a ;
	FILE *redlog  ;
	char video_source  [MAX_LEN_DATA] ;
	char text_source  [MAX_LEN_DATA] ;
	
	
};




struct Data 
{
    /* data */
    int pos ;
    char *result ;
};


struct String {
	
   size_t  len ; 
   int pos  ;
   char *buffer  ;
   char string_data [MAX_BUF_STR];
};


Data * findPattern  (const char  *src  , const char *rep);
String *replaceSubStr(const char *s, const char *s1, const char *s2) {
    if (!s || !s1 || !s2 || strlen(s1) == 0)
        return NULL;

    String *string = (String *)malloc(sizeof(String));
    if (!string) return NULL;

    memset(string->string_data, 0, MAX_BUF_STR);
    string->buffer = (char *)malloc(MAX_BUF_STR);
    if (!string->buffer) {
        free(string);
        return NULL;
    }

    size_t i = 0;
    size_t slen = strlen(s), s1len = strlen(s1);
    
    while (i < slen) {
        if (i + s1len <= slen && strncmp(&s[i], s1, s1len) == 0) {
            strcat(string->string_data, s2);
            i += s1len;
			string->len ++ ;
        } else {
            size_t len = strlen(string->string_data);
			int dif=((int)MAX_BUF_STR )- 1;
            if ((len < dif))
                string->string_data[len] = s[i];
			
            i++;
			string->len ++ ;
        }
    }

    strcpy(string->buffer, string->string_data);
    string->len = strlen(string->string_data);
    return string;
}
String *  replaceSubStrv1 (  char * s , char *s1 , char *s2)


{
	
  String  * string  =(String * ) malloc(sizeof(String )) ;
  size_t  slen =  strlen (s) ; 
  size_t  serlen = strlen (s1 ) ;
  size_t replen = strlen( s2 ) ;
  int   i = 0 ;
  Data *data  =(Data * )malloc (sizeof(Data )) ;
  
  if(slen == 0 || serlen == 0 || replen == 0 )
	    return NULL ;
  
  string->buffer = (char * ) malloc (sizeof(char ) * MAX_BUF_STR * slen  ) ;
  strcpy(string->string_data ,"" ); 
  for (; i < slen ; i++) {
	       if (i + serlen <= slen) {
			   strncpy(string->buffer,&s[i] , slen ) ;
	           data = findpatern (string->buffer ,  s1 ) ;
			   string->pos = i ;
			   i += serlen - 1 ;	
			        if(data)
				        if(data->result[0] == s1[0] )
			          strcat(string->string_data ,  s2 ) ;
			        else 
						strcat(string->string_data , &s[i] ) ;
			   
		   }else strcat(string->string_data , &s[i] );
   }
   if(strlen(string->string_data )  > 0 ) 
	    strcpy (string->buffer , string->string_data ) ;
   else strcpy(string->buffer , s ) ;
   string->len =strlen(string->string_data ) ;
   
   return string ;
}



Data  *findpatern(const char *src  , const char *rep)
{

    size_t srclen  = strlen(src);
    size_t replen = strlen(rep);
    char *result  ;
    Data *data  =(Data *) malloc(sizeof(Data)) ;
    if(replen == 0 ||  rep ==NULL ||  srclen<=replen || src==NULL)
       return NULL  ;
    result =strstr(src ,rep) ;
    if(result==NULL) return NULL ;
	data->result  = (char * ) malloc(sizeof(char ) * strlen(result ) *MAX_BUF_STR) ;
    strcpy(data->result , result) ;
    data->pos  = result - src ;
    return data;
}










