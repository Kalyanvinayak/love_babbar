#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class babbar
{
public:
    int mysqrt(int x)
    {
        int left = 0;
        int right = x / 2;
        int ans = -1;
        if (x == 0)
            return 0;
        if (x < 4)
            return 1;
        while (left <= right)
        {
            long long int middle = left + (right - left) / 2;
            if ((middle * middle) > x)
                right = middle - 1;
            else
            {
                left = middle + 1;
                ans = middle;
            }
        }
        return ans;
    }

    bool binary_search(vector<int> v, int target)
    {
        int left = 0;
        int right = v.size() - 1;
        while (left <= right)
        {
            int middle = (left + right) / 2;

            // There's a high chance that the integer might overflow as the sum of (left + right) can exceed the integer limit which is ( -2^31 , 2^31 ). So, in order to avoid this we use another methods such as -->  int middle = left + (right-left)/2. OR  int middle = left/2 + right/2 .

            if (target == v[middle])
                return true;
            else if (target > v[middle])
                left = middle + 1;
            else
                right = middle - 1;
        }
        return false;
    }
    int FindFirstOccurence(vector<int> v, int target)
    {
        int left = 0;
        int right = v.size() - 1;
        int ans = -1;
        while (left <= right)
        {
            int middle = (left + right) / 2;
            if (target == v[middle])
            {
                ans = middle;
                right = middle - 1;
            }
            else if (target > v[middle])
                left = middle + 1;
            else
                right = middle - 1;
        }
        return ans;
    }
    int FindLastOccurence(vector<int> v, int target)
    {
        int left = 0;
        int right = v.size() - 1;
        int ans = -1;
        while (left <= right)
        {
            int middle = (left + right) / 2;
            if (target == v[middle])
            {
                ans = middle;
                left = middle + 1;
            }
            else if (target > v[middle])
                left = middle + 1;
            else
                right = middle - 1;
        }
        return ans;
    }
    int MissingNumber(vector<int> v)
    {
        int left = 0;
        int right = v.size() - 1;
        int ans = -1;
        while (left <= right)
        {
            int middle = (left + right) / 2;
            if (v[middle] - middle == 1)
                left = middle + 1;
            else if (v[middle] - middle > 1)
            {
                ans = middle + 1;
                right = middle - 1;
            }
            if (ans + 1 == 0)
                return v.size() + 1;
            else
                return ans;
        }
    }
    int SearchInSortedAndRotatedArray(vector<int> &v)
    {
        int left = 0;
        int right = v.size() - 1;
        while (left <= right)
        {
            if (left == right)
                return left;
            int middle = (left + right) / 2;
            if (v[middle] > v[middle + 1])
                return middle;
            else if (v[middle - 1] > v[middle])
                return middle - 1;
            else if (v[left] > v[middle])
                right = middle - 1;
            else
                left = middle + 1;
        }
        return -1;
    }
    bool binary2dSearch(vector<vector<int>> v, int target)
    {
        int row=v.size();
        int column=v[0].size();
        int total_elements=row*column;
        int left=0;
        int right=total_elements-1;
        while(left<=right)
        {
            int middle=left+(right-left)/2;
            // We know how to convert 2D array to 1D array using the formula (Column*i)+j. Now let's learn to go from 1-D Array to 2-D array.
            int rowindex=middle/column; //This is i in the format of v[i][j]
            int colindex=middle%column; //This is j in the format of v[i][j]
            int current_element=v[rowindex][colindex];
            if(current_element==target)
            return true;
            else if(current_element<target)
            left=middle+1;
            else
            right=middle-1;
        }
        return false;
    }
    /* int RotateArray(vector<int> &v)
     {

     }*/
};
int main()
{
    babbar obj;

    int sw;
    do
    {
        cout << "You've entered the binary search program tell me what operation do you want to perform regarding binary search . " << endl
             << "Enter 1 : To check if an element is present or not" << endl
             << "Enter 2 : To find the first occurence for any number" << endl
             << "Enter 3 : To find the last occurence for any number" << endl
             << "Enter 4 : To find the total occurence for any number" << endl
             << "Enter 5 : To find the missing number in the sorted array" << endl
             << "Enter 6 : To find in a sorted and rotated array" << endl
             << "Enter 7 : To find the square root of a given number " << endl
             << "Enter 8 : To find an element in 2D Matrix"<<endl
             << "Enter 0 : To quit" << endl;
        cin >> sw;

        switch (sw)
        {
        case 0:
        {
            break;
        }
        case 1:
        {
            int n;
            cout << "Enter the size of array you want to create to perform binary search on" << endl;
            cin >> n;
            vector<int> v(n, 0);
            for (int i = 0; i < n; i++)
            {
                cout << "Enter the data in the vector : ";
                cin >> v[i];
            }
            sort(v.begin(), v.end());
            int key;
            cout << "Enter the key you want to find in the vector : ";
            cin >> key;
            cout << obj.binary_search(v, key);
            break;
        }
        case 2:
        {
            int n;
            cout << "Enter the size of array you want to create to perform binary search on" << endl;
            cin >> n;
            vector<int> v(n, 0);
            for (int i = 0; i < n; i++)
            {
                cout << "Enter the data in the vector : ";
                cin >> v[i];
            }
            sort(v.begin(), v.end());
            int key;
            cout << "Enter the key you want to find in the vector : ";
            cin >> key;
            int FirstOccurence = obj.FindFirstOccurence(v, key);
            if (FirstOccurence < 0)
            {
                cout << "The element wasn't found in the given array/vector" << endl;
                return 0;
            }
            cout << "The Key was first found in index : " << FirstOccurence << endl;
            break;
        }
        case 3:
        {
            int n;
            cout << "Enter the size of array you want to create to perform binary search on" << endl;
            cin >> n;
            vector<int> v(n, 0);
            for (int i = 0; i < n; i++)
            {
                cout << "Enter the data in the vector : ";
                cin >> v[i];
            }
            sort(v.begin(), v.end());
            int key;
            cout << "Enter the key you want to find in the vector : ";
            cin >> key;
            int LastOccurence = obj.FindLastOccurence(v, key);
            if (LastOccurence < 0)
            {
                cout << "The element wasn't found in the given array/vector" << endl;
                return 0;
            }
            cout << "The Key was last found in index : " << LastOccurence << endl;
            break;
        }
        case 4:
        {
            int n;
            cout << "Enter the size of array you want to create to perform binary search on" << endl;
            cin >> n;
            vector<int> v(n, 0);
            for (int i = 0; i < n; i++)
            {
                cout << "Enter the data in the vector : ";
                cin >> v[i];
            }
            sort(v.begin(), v.end());
            int key;
            cout << "Enter the key you want to find in the vector : ";
            cin >> key;
            int FirstOccurence = obj.FindFirstOccurence(v, key);
            if (FirstOccurence < 0)
            {
                cout << "The element wasn't found in the given array/vector" << endl;
                return 0;
            }
            int LastOccurence = obj.FindLastOccurence(v, key);
            cout << "The total occurence of the target can be fethced by the formula Last occurence - First occurence +1 i.e. : " << LastOccurence - FirstOccurence + 1 << endl;
            break;
        }
        case 5:
        {
            int n;
            cout << "Enter the size of array you want to create to perform binary search on" << endl;
            cin >> n;
            vector<int> v(n, 0);
            for (int i = 0; i < n; i++)
            {
                cout << "Enter the data in the vector : ";
                cin >> v[i];
            }
            sort(v.begin(), v.end());
            int miss = obj.MissingNumber(v);
            cout << "The missing number is : " << miss << endl;
            break;
        }
        case 6:
        {
            int n;
            cout << "Enter the size of array you want to create to perform binary search on" << endl;
            cin >> n;
            vector<int> v(n, 0);
            for (int i = 0; i < n; i++)
            {
                cout << "Enter the data in the vector : ";
                cin >> v[i];
            }
            int pivot = obj.SearchInSortedAndRotatedArray(v);
            cout << pivot << " and " << v[pivot] << endl;
            break;
        }
        case 7:
        {
            int n;
            cout << "Enter the no. u want square root of :-" << endl;
            cin >> n;
            cout << "RESULT " << obj.mysqrt(n) << endl;
            break;
        }
        case 8:
        {
            int m;
            cout<<"Enter the number of rows : ";
            cin>>m;
            int n;
            cout<<"Enter the number of columns : ";
            cin>>n;
            vector<vector<int>> v(m,vector<int>(n,0));
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cin>>v[i][j];
                }
            }
            // Just search how to sort 2-D Array.
            cout<<"Printing the input matrix after sorting"<<endl;
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cout<<v[i][j]<<"  ";
                }
                cout<<endl;
            }
            int key;
            cout<<"Enter the element you want to search :";
            cin>>key;
            cout<<obj.binary2dSearch(v,key)<<endl;
            break;
        }
        default:
        {
            cout << "Invalid input" << endl;
            break;
        }
        }
    } while (sw != 0);
    cout << "Program Ended successfully" << endl;
    return 0;
}
hgjhg
jkjg