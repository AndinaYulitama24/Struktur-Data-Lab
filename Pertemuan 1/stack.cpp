#include <iostream>
using namespace std;

#define MAX 5
int stack[MAX];
int top = -1;

//Push
void push(int value){
    if( top == MAX - 1){
        cout <<" stack penuh !\n ";
    }else {
        top++;
        stack[top]=value;
        cout << value << " Ditambahakan dalam stack\n ";
    }
}

//pop
void pop(){
    if(top == -1){
        cout<<" stack kosong !\n";
    } else{
        cout <<"\n"<< stack[top]<<" dihapuskan dari stack\n ";
        top--;
    }
}
//nampilkan stack
void display(){
    if(top == -1){
        cout<<" stack kosong !\n";
    }else{
        cout<<" \nISI stack :\n ";
        for (int  i = top; i >= 0;i--){
            cout << stack[i]<<" ";
        }
    }
}

int main(){
    push(50);
    push(40);
    push(30);
    push(20);
    push(10);

    display();
    pop();
    display();

    return 0;
}