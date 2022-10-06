#include <iostream>
#include <stack>
using namespace std;

void span(int rates[], int days, int stockspan[]){

  stack<int> stack; 

  stockspan[0] = 1;
  stack.push(0);

  for(int i=1; i<days; i++) 
  {
    while(rates[i] > rates[stack.top()])
    {
      stack.pop();

      if(stack.empty()) 
      {
        break;
      }
    }

    if(!stack.empty())
    {
      stockspan[i] = i - stack.top();
    }
    else
    {
      stockspan[i] = i+1;
    }

    stack.push(i);

  }
}
int main() {

  int size = 6;
  int rates[size] = {31,27,14,21,30,22};
  int stockspan[size];

  span(rates, size, stockspan);

  for(int i=0; i<size; i++)
  {
    cout<< stockspan[i] << ", ";
  }
  
}