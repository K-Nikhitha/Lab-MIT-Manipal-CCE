#include<iostream>
using namespace std;

class node{
    public:
        int coef;
        int exp;
        node *next, *prev;
        node *first = NULL;
        void display(node *);
        node* attach(int, int, node *);
        node* read_poly(node *);
        node* poly_add(node *, node *);
};

void node::display(node *first){
    node *temp;
    if(first==NULL) cout<<"Polynomial does not exist.\n";
    temp=first;
    while(temp!=NULL){
        cout<<"+"<<" "<<temp->coef<<"x^"<<temp->exp<<" ";
        temp = temp->next;
    }
}

node *node::attach(int coef, int exp, node *first){
    node *temp=new node;
    node *cur;
    temp->coef = coef;
    temp->exp = exp;
    temp->next = NULL;
    temp->prev = NULL;
    if(first==NULL) return temp;
    cur = first;
    while(cur->next!=NULL) cur=cur->next;
    cur->next=temp;
    temp->prev = cur;
    return first;
}

node *node::read_poly(node *first){
    int coef, exp,i = 0;
    cout<<"Enter '-999' to end the polynomial.\n";
    while(1){
        cout<<"Enter the term "<<i++<<" :"<<endl;
        cout<<"Coefficient = ";
        cin>>coef;
        if(coef==-999) break;
        cout<<"Exponent = ";
        cin>>exp;
        first = attach(coef, exp, first);
    }
    return first;
}

node *node::poly_add(node *a, node *b){
    node *c=NULL;
    int coef, com;
    while(a!=NULL && b!=NULL){
        if(a->exp == b->exp){
            coef=a->coef+b->coef;
            c = attach(coef, a->exp, c);
            a = a->next;
            b = b->next;
        }
        else if(a->exp> b->exp){
            c = attach(a->coef, a->exp, c);
            a = a->next;
        }
        else{
            c = attach(b->coef, b->exp, c);
            b = b->next;
        }
    }
    while(a!=NULL){
        c = attach(a->coef, a->exp, c);
        a = a->next;
    }
    while(b!=NULL){
    c = attach(b->coef, b->exp, c);
    b = b->next;
    }
    return c;
}

int main(){
    node *poly1 = NULL, *poly2 = NULL, *poly3 = NULL, p;
    cout<<"Enter the first polynomial:\n";
    poly1 = p.read_poly(poly1);
    cout<<"Enter the second polynomial:\n";
    poly2 = p.read_poly(poly2);
    poly3 = p.poly_add(poly1, poly2);
    cout<<"After adddtion:\n";
    p.display(poly3);
}
