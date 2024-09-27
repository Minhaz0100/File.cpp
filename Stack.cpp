#include <iostream>
using namespace std;

class Stack

{
private:

    int top, a[5];

public:

    Stack()
    {
        top = -1;
        for (int i=0; i<5; i++)
        {
            a[i]=0;
        }
    }

    bool isEmpty()
    {
        if(top == -1)
            return true;
        else 
            return false;
    }

    bool isFull()
    {
        if(top == 4)
            return true;
        else 
            return false;
    }
    
    void push(int val)
{
    if (isFull())
    {
        cout << "Stack Overflow, replacing bottom item and adding to top" << endl;
        for (int i = 1; i <= 4; i++)
        {
            a[i - 1] = a[i];
        }
        a[top] = val;
    }
    else
    {
        top++;
        a[top] = val;
    }
}

    int pop()
    {
        if(isEmpty())
        {
            cout<<"Stack Underflow"<<endl;
            return 0;
        }
        else
        {
            int popValue = a[top];
            a[top] = 0;
            top--;

            return popValue;
        }
    }

    int count()
    {
        return top+1;
    }

    int peek(int pos)
    {
        if(isEmpty())
        {
            cout<<"Stack Underflow"<<endl;
            return 0;
        }
        else 
            return a[pos];
    }

    void change(int pos, int val)
    {
        a[pos]=val;
        cout<<"Value changed at location "<<pos<<endl;
    }

    void display()
    {
        cout<<"All value in the Stack are"<<endl;

        for(int i=4; i>=0; i--)
        {
            cout<<a[i]<<endl;
        }
    }
};

int main()
{
    Stack s;
    
    int option, position, value;

    do
    {
        cout<<"What operation do you want to perform? Select option number, Enter 0 to exit."<<endl;
        cout<<"1. Push()"<<
        endl<<"2. Pop()"<<
        endl<<"3. isEmpty()"<<
        endl<<"4. isFull()"<<
        endl<<"5. peek()"<<
        endl<<"6. count()"<<
        endl<<"7. change()"<<
        endl<<"8. display()"<<
        endl<<"9. Clear Screen"<<endl<<endl;

        cin>>option;
        switch(option)
        {
            case 0:
                break;

            case 1:
                cout<<"Enter an item to push in the stack"<<endl;
                cin>>value;
                s.push(value);
                break;

            case 2:
                cout<<"Pop function called - Poped Value: "<<s.pop()<<endl;
                break;

            case 3:
                if(s.isEmpty())
                    cout<<"Stack is Empty"<<endl;
                else
                    cout<<"Stack is not Empty"<<endl;
                break;

            case 4:
                if(s.isFull())
                    cout<<"Stack is Full"<<endl;
                else 
                    cout<<"Stack is not Full"<<endl;
                break;

            case 5:
                cout<<"Enter position of item you want to peek: "<<endl;
                cin>>position;
                cout<<"Peek function called - Value at position "<<position<<" is "<<s.peek(position)<<endl;
                break;

            case 6:
                cout<<"Count function called - Number of items in the Stack are: "<<s.count()<<endl;
                break;

            case 7:
                cout<<"Change function called - "<<endl;
                cout<<"Enter position of item you want to change: ";
                cin>>position;
                cout<<endl;
                cout<<"Enter value of item you want to change: ";
                cin>>value;
                s.change(position,value);
                break;

            case 8:
                cout<<"Display function called - "<<endl;
                s.display();
                break;

            case 9:
                system("cls");
                break;
                
            default:
                cout<<"Enter proper option number "<<endl; 
        }

    } while (option != 0);
    
    return 0;
}
