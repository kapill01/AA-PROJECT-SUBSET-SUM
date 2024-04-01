#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void SSP(int N, int elements[], int C)
{
    int K;
    int Psum;
    vector<int> bitmap(N, 0);
    int tSS = 0;
    int iter = 0;

    // step1
    sort(elements, elements + N);

    // step 2
    while (elements[N - 1] > C)
    {
        N -= 1;
    }
    K = N;

    // step 3
    for (int i = K - 1; i >= 0; i--)
        bitmap[i] = 0;

    // step 4
    Psum = 0;
    while (1)
    {
        // step 5
        for (int i = K - 1; i >= 0; i--)
        {
            if (Psum + elements[i] <= C)
            {
                bitmap[i] = 1;
                Psum += elements[i];
            }
        }

        // step 6
        if (Psum == C)
        {
            tSS++;
            cout << "{ ";
            for (int i = 0; i < N; i++)
            {
                if (bitmap[i] == 1)
                    cout << elements[i] << " ";
            }
            cout << "} ";
        }

        // step 7
        int j = 0;
        bool found = false;
        while (j <= N - 1 and !found)
        {
            if (bitmap[j] == 0 and bitmap[j + 1] == 1)
                found = true;
            else
                j++;
        }

        // step 8
        if (!found)
        {
            // no more soln goto 11
            break;
        }
        else
        {
            bitmap[j] = 1;
            bitmap[j + 1] = 0;
            for (int i = j - 1; i >= 0; i--)
            {
                bitmap[i] = 0;
            }
        }

        // step 9
        Psum = 0;
        for (int i = N - 1; i >= j; i--)
        {
            if (bitmap[i] == 1)
                Psum += elements[i];
        }
        // step 10
        K = j;
        iter++;
    }
    // step 11
    cout << "\nTotal Iterations : " << iter << "  No of subsets : " << tSS;
}

int main()
{
    int N;
    cout << "Enter the number of elements: ";
    cin >> N;

    int elements[N];
    cout << "Enter the elements: ";
    for (int i = 0; i < N; i++)
    {
        cin >> elements[i];
    }

    int C;
    cout << "Enter the target sum: ";
    cin >> C;

    cout << "Subsets with sum equal to " << C << ":" << endl;
    SSP(N, elements, C);

    return 0;
}