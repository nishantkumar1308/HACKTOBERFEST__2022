#include<bits/stdc++.h>

using namespace std;

// function for calculation of largest sum
int maxSumDHelix(int A1[], int A2[], int n1, int n2) {
        int i, j = 0, path1 = 0, path2 = 0, pathsum = 0;

        // n1, n2 are length of both sequences
        for (i = 0; i < n2; i++) {
                // add elements to path2
                path2 += A2[i];

                // add elements to pat1
                while (j < n1 && A1[j] < A2[i]) {
                        path1 += A1[j];
                        j++;
                }

                // at intersection point update
                // path1 path2 and pathsum
                if (j < n1 && A1[j] == A2[i]) {
                        path1 += A1[j];
                        pathsum += max(path1, path2);

                        //reset
                        path1 = 0;
                        path2 = 0;
                        j++;
                }
        }

        // if n1 &amp;gt; n2
        while (j < n1) {
                path1 += A1[j];
                j++;
        }
        // final result
        pathsum += max(path1, path2);
        return pathsum;
}

// driver program
int main() {
        int n1, n2;
        cout << "Enter size of 1st array :";
        cin >> n1;
        int A1[n1];
        cout << "\nEnter elements of 1st array:\n";
        for (int i = 0; i < n1; i++)
                cin >> A1[i];
        cout << "Enter size of 2nd array:";
        cin >> n2;
        int A2[n2];
        cout << "\nEnter elements of 2nd array:\n";
        for (int i = 0; i < n2; i++)
                cin >> A2[i];
        cout << "The largest possible sum = " << maxSumDHelix(A1, A2, n1, n2);
        return 0;
}
