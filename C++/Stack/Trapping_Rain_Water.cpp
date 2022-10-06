#include <iostream>
using namespace std;

int trapped_water(int elevation_map[], int n)
{
  int water = 0; 

  
  int left_max[n];
  int right_max[n];

  left_max[0] = elevation_map[0];
  right_max[n-1] = elevation_map[n-1];

  for(int i=1; i<n; i++)
  {
    if(left_max[i-1] > elevation_map[i])
    {
      left_max[i] = left_max[i-1];
    }
    else{
      left_max[i] = elevation_map[i];
    }
  }


  for(int i=n-2; i >= 0; i--)
  {
    if(right_max[i+1] > elevation_map[i])
    {
      right_max[i] = right_max[i+1];
    }
    else{
      right_max[i] = elevation_map[i];
    }
  }
  
  int min_max; 

  for(int i=0; i<n; i++)
  {
    if(left_max[i] < right_max[i])
    {
      min_max = left_max[i];
    }
    else{
      min_max = right_max[i];
    }

    water += min_max - elevation_map[i];

  }

  return water;

}

int main() {

  int elevation_map[14] = {1, 2, 1, 3, 1, 2, 1, 4, 1, 0, 0, 2, 1, 4};
  
  cout<<"Total units of water trapped: "<<trapped_water(elevation_map, 14);

}