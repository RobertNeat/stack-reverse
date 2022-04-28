//  reads file data.txt
//  create file output.txt with reversed text

#include <iostream>
#include <fstream>

using namespace std;

struct element{ //stack structure
    int number;
    element* next;
};

void push_stack(element* &stack, int value){    //adds element to stack
    element* el=new element;
    el->number=value;
    el->next=stack;
    stack= el;
}

void pop_stack(element* &stack){    //drops element from stack
    element* temp=stack;
    stack=stack->next;
    delete temp;
}

bool isEmpty_Stack(element* stack){ //check if stack is empty
    if(stack==nullptr){
        cout<<"Stack is empty"<<endl;
        return true;
    }
    else{
        cout<<"Stack contains something"<<endl;
        return false;
    }
}

int top_stack(element* stack){  //shows the most recent element
    return stack->number;
}

void reverseOrder(element* &stack,ifstream &file, ofstream &output){
        string textLine;

        while(!(file.eof())){
            getline(file,textLine);

            for(int a=0;a<textLine.length();a++){    //writes line of file into string variable
                push_stack(stack,textLine[a]);
            }
            cout<<textLine<<endl;

            for(int a=0;a<textLine.length();a++){    //adds elements from string to stack
                output<<char(top_stack(stack));  //conversion to char (stack uses chars and functions does also)
                pop_stack(stack);
            }
            output<<endl;    //every time line needs end (getline deletes delimiters)
    }}

void line(){
    cout<<"\n--------------------------------------------------------------\n";
}

int main()
{
    line();
    element* stack=nullptr;

    ifstream file;
    file.open("data.txt");


    ofstream output;
    output.open("output.txt");

    reverseOrder(stack,file,output);
        output.close();
        file.close();

    line();
    cout<<"Reverse complete - check file \"output.txt\" inside your project directory"<<endl;
    line();
    return 0;
}
