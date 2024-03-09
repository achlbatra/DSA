#include<stdio.h>

void saydigit(int n, char arr[][10])
{
    //base case
    if(n==0)return;
    

    //processing
    int d = n%10;
    n=n/10;


    //recursive call
    saydigit(n,arr);
    printf("%s\t",arr[d]);

}
int main()
{
    int n;
    char arr[10][10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    scanf("%d",&n);

    saydigit(n,arr);
}