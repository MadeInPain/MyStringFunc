/*
 * simple cstring func, learning purpose, noob level
 *
*/

#include <iostream>

using namespace std;

int MyStrlen(const char *);
void MyStrcpy(char *, const char *);
int MyStrcmp(const char *, const char *);

void MyCut(const char* , char*, const unsigned int index = 0, const unsigned int count = 1);
char * MyDCut(const char*, const unsigned int index = 0, const unsigned int count = 1);

void MyCat(const char *, const char *, char *);
char * MyDCat(const char *, const char *);

int MyAtoi(const char*);



int main(){

    char s1[20], s2[20], s3[40];
    int startIndex = 0, size = 0, mode;


    cout << "Hello World!" << endl;
    cout << MyStrlen("Hello World!") << endl;

    char str[] = "abcd";
    MyStrcpy(str, "babac");

    cout << str << endl;

    cout << "enter an operation" << endl;
    //legend
    cout << "0 - Cat\n1 - Cut\n2 - DCut\n3 - Strcmp\n4 - Atoi" << endl;


    while(cin >> mode){
        switch (mode) {
        case 0:
            //MyCat demo
            cout << "cat(s1, s1, s3): ";
            cin >> s1, cin >> s2;
            MyCat(s1, s2, s3);
            cout << s3 << endl;
            cin.clear();
            break;
        case 1:
            // MyCut demo
            cout << "cut(s1, s2, startIndex, size): ";
            cin >> s1, cin >> startIndex, cin >> size;
            MyCut(s1, s2, startIndex, size);
            cout << s2 << endl;
            cin.clear();
            break;
        case 2:
            //MyDCut demo
            cout << "dynamic cut(s1, startIndex, size): ";
            cin >> s1, cin >> startIndex, cin >>size;
            char * ptr; //for string in heap
            ptr = MyDCut(s1, startIndex, size);
            cout << ptr << endl;
            delete[] ptr;
            cin.clear();
            break;
        case 3:
            //compare demo
            while(cin){
                cout << "Strcmp(s1, s2): \n";
                cin >> s1, cin >> s2;
                cout << MyStrcmp(s1, s2) << endl;
            }
            cin.clear();
            break;
        case 4:
            //Atoi demo
            while(cin){
                cout << "Atoi(s1): " << endl;
                cin >> s1;
                cout << MyAtoi(s1) << endl;
            }
            cin.clear();
            break;
        default:
            cout << "wrong number!" << endl;
            break;
        }
        cout << "enter an operation" << endl;
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

    while(*arg0 && *arg1){
        *(arg0++) = *(arg1++);
    }
}

/*
 * compare two char_array
 */
int MyStrcmp(const char * arg0, const char *arg1){
    while(*arg0 && (*arg0) == (*arg1)){ //if *arg0 != 0 and &arg0 == *arg1 (*arg1 != 0 too)
       ++arg0, ++arg1;
    //do nothing
    }
    if(*arg0 > *arg1)
        return 1;
    else if(*arg0 < *arg1)
        return -1;
    return 0;
}

/*
 * cut cstring
 */
void MyCut(const char * arg0, char * arg1, const unsigned int index, const unsigned int count){
    unsigned int size = index+count;
    for(unsigned int i = index; i < size; ++i){
        *arg1++ = *(arg0 + i);
    }
}

/*
 * cut cstring using heap
 */
char * MyDCut(const char * arg0, const unsigned int index, const unsigned int count){
    char * result = new char[20];
    if(!result){
        cout << "alloc failed" << endl;
        return nullptr;
    }
    //unsigned int size = index+count;

    for(unsigned int i = 0; i < count; ++i){
        result[i] = arg0[index+i];
    }

    return result;
}

/*
 * concatination
 */
void MyCat(const char * arg0, const char * arg1, char * arg2){
    while(*arg2++ = *arg0++){}
    --arg2;
    while(*arg2++ = *arg1++){}
}

/*
 * atoi (cstring to integer)
 */
int MyAtoi(const char *c){
    int res = 0;
    for(;isdigit(*c); ++c){
        if(res){
            res = res * 10 + *c - 48; // 10 because decimal numeral system, '1' = 49
        }
        else{ //firs step, count = 0
            res = *c - 48;
        }
    }
    return res;
}














