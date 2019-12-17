#include <iostream>
#include <string.h>
using namespace std;

//只要前i项的和还没有小于0那么子序列就一直向后扩展，
//否则丢弃之前的子序列开始新的子序列，同时我们要记下各个子序列的和，最后找到和最大的子序列
int maxSubSum(int a[], int num) {//最大连续子序列和
    int max = -999;
    int val = 0;
    for (int i = 0; i < num; i++) {
        val += a[i];
        if (val < 0) {
            val = 0;
        }
        else {
            if (max < val)
                max = val;
        }
    }

    return max;
}

//找到所有比arr[i]小的arr[j]，且j<i，
//中最长的那一个再加1
int longIncSub(int a[], int num) {//最长递增子序列
    int b[num];
    b[0] = 1;

    for (int i = 0; i < num; i++) {
        int max = 0;
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j] && max < a[j])
                max = a[j];
        }
        max += 1;
        b[i] = max;
    }
    return b[num-1];
}

//最长公共子序列 同时可以记录是从哪个方向取的 再从最后一个往前找到第一个
int lcs(const char* a, const char* b) {
    int alen = strlen(a);
    int blen = strlen(b);
    int save[alen+1][blen+1];//i-1或j-1有小于0的情况 因此多用一个 且为0的也要初始为0
    for (int i = 0; i <= alen; i++)
        save[i][0] = 0;
    for (int i = 0; i <= blen; i++)
        save[0][i] = 0;

    for (int i = 1; i <= alen; i++) {
        for (int j = 1; j <= blen; j++) {
            if (a[i-1] == b[j-1])//这里注意下
                save[i][j] = save[i-1][j-1] + 1;
            else
                save[i][j] = save[i-1][j] > save[i][j-1] ? save[i-1][j] : save[i][j-1];

        }
    }
    return save[alen][blen];
}
//最长公共子串 串要求是连续的
int lcstring(const char* a, const char* b) {
    int alen = strlen(a);
    int blen = strlen(b);
    int save[alen][blen];

    for (int i = 0; i < alen; i++) {
        for (int j = 0; j < blen; j++) {
            if (a[i] == b[j]) {
                if (i-1 < 0 || j-1 < 0)
                    save[i][j] = 1;
                else
                    save[i][j] = save[i-1][j-1] + 1;
            }
            else
                save[i][j] = 0;
        }
    }

    int max = 0;
    for (int i = 0; i < alen; i++)
        for (int j = 0; j < blen; j++)
            if (save[i][j] > max)
                max = save[i][j];

    return max;
}
//最长回文子序列
int lps(const char* s, int low, int high) {
    if (s == NULL || s == "")
        return 0;

    if (low == high)
        return 1;
    if (low > high)
        return 0;

    if (s[low] == s[high])
        return lps(s, low + 1, high - 1) + 2;
    else {
        int temp1 = lps(s, low, high - 1);
        int temp2 = lps(s, low + 1, high);
        return temp1 > temp2 ? temp1 : temp2;
    }
}

int main() {
    int a[4] = {5,-3,4,2};
    cout << maxSubSum(a, 4) << endl;
    int b[4] = {5,-6,4,2};
    cout << maxSubSum(b, 4) << endl;

    int c[6] ={1,5,8,2,3,4};
    cout << longIncSub(c, 6) << endl;
    int d[6] ={6,5,5,4,3,2};
    cout << longIncSub(d, 6) << endl;

    cout << lcs("baob", "caba") << endl;

    cout << lcstring("baob", "caba") << endl;

    cout << lps("amama", 0, 4) << endl;
    return 0;
}
