#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void calculate_sub_array(void);
int max(int, int);
int main() {
    int num_cases,i;
    cin >> num_cases;
    for (i=0;i<num_cases;i++)
        calculate_sub_array();
    return 0;
}

void calculate_sub_array()
    {
    int num_elements,best_sum=0,current_sum=0,i,max_element,sum=0;
    cin >> num_elements;
    int elements[num_elements];
    for (i=0;i<num_elements;i++)
        {        
        cin >> elements[i];
        if (elements[i] > 0) sum+=elements[i];
        }
    max_element=elements[0];
    for (i=0;i<num_elements;i++)
        {
        if (max_element<elements[i]) max_element=elements[i];
        current_sum=max(elements[i]+current_sum,0);
        best_sum=max(best_sum,current_sum);      
        }
    if (max_element<1)
        printf("%d %d\n",max_element,max_element);
    else
        printf("%d %d\n",best_sum,sum);
    }
int max(int a, int b)
    {
    return a>b?a:b;
    }

