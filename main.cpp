/*
 * write func:
 * strlen(), strcpy(), strcmp()
*/

#include <iostream>

using namespace std;

int MyStrlen(const char *);
void MyStrcpy(char *, const char *);
int MyStrcmp(const char *, const char *);


int main()
{
    cout << "Hello World!" << endl;
    cout << MyStrlen("Hello World!") << endl;

    char str[] = "abcd";
    MyStrcpy(str, "babac");

    cout << str << endl;

    while(cin){
        char s1[20], s2[20];
        cin >> s1, cin >> s2;
        cout << MyStrcmp(s1, s2) << endl;
    }

    return 0;
}


/*
* calc number of characters in char_array, without terminal '\0'
*/
int MyStrlen(const char * arg0){
    int count = 0;
    for(; *arg0 != '\0'; ++arg0){
        ++count;
    }
    return count;
}

/*
 * copy char_array from arg1 to arg0;
 */
void MyStrcpy(char * arg0, const char * arg1){

    for(;(*arg0 != '\0') && (*arg1 != '\0'); ++arg0, ++arg1){
        *arg0 = *arg1;
    }
}

/*
 * compare two char_array
 */
int MyStrcmp(const char * arg0, const char *arg1){
    while((*arg0 != '\0') && (*arg0 != '\0') && (*arg0) == (*arg1)){
       ++arg0, ++arg1;
    //do nothing
    }
    if(*arg0 > *arg1)
        return 1;
    else if(*arg0 < *arg1)
        return -1;
    return 0;
}

