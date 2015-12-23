#include <iostream>
#include <string>

typedef long long int Int;
typedef std::string String;
#define print std::cout<< 

String convertToLatinNumber(Int num){
    String res;
    Int latin_num[9];
    Int latin_fixed_value[9]={1000,500,100,50,10,9,5,4,1};
    String latin_fixed_char[9]={"m","d","c","l","x","ix","v","iv","i"};
    for(int i=0;i<9;i++){
        latin_num[i] = num / latin_fixed_value[i];
        num = num % latin_fixed_value[i];
    }
    for(int i=0;i<9;i++){
        for(int j=0;j<latin_num[i];j++)res+=latin_fixed_char[i];
    }
    return res;
}

int main(){
    int a;
    print "Enter number: ";
    std::cin>>a;
    print convertToLatinNumber(a)+"\n";
    main();
    return 0;
}
