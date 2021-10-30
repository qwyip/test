
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int power, coefficient;
    struct Node *next;
}Node;

int main()
{
    int power, coefficient;
    char choice[30]={};
    char namea[50]={};
    char nameb[50]={};
    char pwriteresult[50]={};
    char display[50]={};
    char display1[50]={};
    char display2[50]={};

    int times=0;
    Node *p = NULL, *q = NULL, *r = NULL;

    void createPoly(Node **, int coeff, int pow);
    void createsubPoly(Node **, int coeff, int pow);
    Node* addPoly(Node *, Node *);
    Node* subbploy(Node *, Node *);
    Node* multiplyPoly(Node*, Node*);
    void displayPoly(Node *);
    double evalcount(Node *,double number);
    void listDestructor(Node **);

    setbuf(stdout, NULL);


    int a;
    float evalnumber=0;

    scanf("%d",&a);
    for(int i=0;i<a;i++){
        scanf("%s", choice);


        if(strncmp(choice, "pread", 3) == 0){

            if(namea[0]=='\0'){
                scanf("%s", namea);
                scanf("%d", &times);
                for(int i=0;i<times;i++){
                    scanf("%d %d", &coefficient, &power);
                    createPoly(&p, coefficient, power);
                }
            }else{
                scanf("%s", nameb);
                scanf("%d", &times);
                for(int i=0;i<times;i++){
                    scanf("%d %d", &coefficient, &power);
                    createPoly(&q, coefficient, power);
                }
            }
            printf("ok\n");
        }else if(strncmp(choice, "pwrite", 3) == 0){
            scanf("%s",display);
            if(strncmp(display, namea, 50) == 0){
                displayPoly(p);
            }else if(strncmp(display, nameb, 50) == 0){
                displayPoly(q);
            }else if(strncmp(display, pwriteresult, 50) == 0){
                displayPoly(r);
            }else{
                printf("error pwrite");
            }
        }else if(strncmp(choice, "padd", 3) == 0){

            scanf("%s",pwriteresult);
            scanf("%s",display1);
            scanf("%s",display2);

            r = addPoly(p, q);

            printf("added\n");
        }else if(strncmp(choice, "psub", 3) == 0){

            scanf("%s",pwriteresult);
            scanf("%s",display1);
            scanf("%s",display2);

            if(strncmp(display1, namea, 50) == 0){
                r=subbploy(p,q);
            }else{
                r=subbploy(q,p);
            }

            printf("substracted\n");
        }else if(strncmp(choice, "pmult", 3) == 0){
            scanf("%s",pwriteresult);
            scanf("%s",display1);
            scanf("%s",display2);


            r = multiplyPoly(p, q);
            printf("multiplied\n");
        }else if(strncmp(choice, "eval", 3) == 0){

            scanf("%s",display);
            scanf("%f",&evalnumber);
            if(strncmp(display, namea, 50) == 0){
                evalcount(p,evalnumber);
            }else if(strncmp(display, nameb, 50) == 0){
                evalcount(q,evalnumber);
            }else if(strncmp(display, pwriteresult, 50) == 0){
                evalcount(r,evalnumber);
            }else{
                printf("error pwrite");
            }


        }else if(strncmp(choice, "perase", 3) == 0){

            scanf("%s",display);

            if(strncmp(display, namea, 50) == 0){
                listDestructor(&p);
            }else if(strncmp(display, nameb, 50) == 0){
                listDestructor(&q);
            }else if(strncmp(display, pwriteresult, 50) == 0){

                listDestructor(&r);

            }else{
                printf("error perase");
            }

            printf("erased\n");

        }else{
            printf("???");
        }
    }
    return 0;
}


void createPoly(Node **p, int coeff, int pow){

    Node *temp = *p, *previous;

    while(temp != NULL){
        if(temp->power <= pow){
            break;
        }

        previous = temp;
        temp = temp->next;
    }

    if(temp == NULL || temp->power != pow){
        Node *newNode = NULL;
        newNode = (Node*) calloc(1, sizeof(Node));
        newNode->coefficient = coeff;
        newNode->power = pow;

        if(*p == temp){
            newNode->next = *p;
            *p = newNode;
        }
        else{
            newNode->next = previous->next;
            previous->next = newNode;
        }

    }
    else{
        temp->coefficient += coeff;
    }
}

void createsubPoly(Node **p, int coeff, int pow){

    Node *temp = *p, *previous;

    while(temp != NULL){
        if(temp->power <= pow){
            break;
        }

        previous = temp;
        temp = temp->next;
    }

    if(temp == NULL || temp->power != pow){
        Node *newNode = NULL;
        newNode = (Node*) calloc(1, sizeof(Node));
        newNode->coefficient = coeff;
        newNode->power = pow;

        if(*p == temp){
            newNode->next = *p;
            *p = newNode;
        }
        else{
            newNode->next = previous->next;
            previous->next = newNode;
        }

    }
    else{
        temp->coefficient -= coeff;
    }
}


Node* addPoly(Node *p, Node *q){

    Node *result = NULL;

    while(p != NULL){

        createPoly(&result, p->coefficient, p->power);
        p = p->next;

    }

    while(q != NULL){

        createPoly(&result, q->coefficient, q->power);
        q = q->next;

    }

    return result;

}

Node* subbploy(Node *p, Node *q){

    Node *result = NULL;

    while(p != NULL){

        createsubPoly(&result, p->coefficient, p->power);
        p = p->next;

    }

    while(q != NULL){

        createsubPoly(&result, q->coefficient, q->power);
        q = q->next;

    }

    return result;
}





Node* multiplyPoly(Node *p, Node *q){

    Node *t = q;
    Node *result = NULL;

    while(p != NULL){

        while(q != NULL){

            createPoly(&result, p->coefficient * q->coefficient, p->power + q->power);
            q = q->next;

        }

        p = p->next;
        q = t;

    }

    return result;

}



double evalcount(Node *p,double number){

    double result;
    double ori=number;

    while(p != NULL){

        if(p->power == 0){
            result=result+(double)p->coefficient;
        }
        else if(p->power > 0){
            for(int i =1;i<p->power;i++){
                number=number*ori;
            }
            result=result+number*(double)p->coefficient;
            number=ori;
        }
        else{
            number=1;
            for(int i =0;i<-p->power;i++){
                number=number/ori;
            }
            result=result+number*(double)p->coefficient;
            number=ori;

        }

        p = p->next;
    }

    printf("%.2f\n",result);
    return result;
}




void displayPoly(Node *p){

    while(p != NULL){

        if(p->power == 0){
            printf("%d",p->coefficient);
        }
        else{
            printf("%dx^%d",p->coefficient,p->power);
        }

        p = p->next;

        if(p != NULL)
            printf("+");

    }

    printf("\n");

}

void listDestructor(Node **p){

    Node *next;

    while(*p != NULL){
        next = (*p)->next;
        free(*p);
        (*p) = next;
    }

}

