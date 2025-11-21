#include<stdio.h>

void Solve()
{
    int num,ans=0;
    scanf("%d",&num);
    for (int i=0; i < num + 1; i++)
    {
        ans += i+1;
    }
    printf("%d\n",ans);

}

int main()
{
    int n;
    scanf("%d",&n);
    while (n--)
    {            
        int num,ans=0;
        scanf("%d",&num);
        for (int i=0; i < num + 1; i++)
        {
            ans += i+1;
        }
        printf("%d\n",ans);
    }
}
