#include <iostream>
#include <string.h>
using namespace std;

//ֻҪǰi��ĺͻ�û��С��0��ô�����о�һֱ�����չ��
//������֮ǰ�������п�ʼ�µ������У�ͬʱ����Ҫ���¸��������еĺͣ�����ҵ�������������
int maxSubSum(int a[], int num) {//������������к�
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

//�ҵ����б�arr[i]С��arr[j]����j<i��
//�������һ���ټ�1
int longIncSub(int a[], int num) {//�����������
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

//����������� ͬʱ���Լ�¼�Ǵ��ĸ�����ȡ�� �ٴ����һ����ǰ�ҵ���һ��
int lcs(const char* a, const char* b) {
    int alen = strlen(a);
    int blen = strlen(b);
    int save[alen+1][blen+1];//i-1��j-1��С��0����� ��˶���һ�� ��Ϊ0��ҲҪ��ʼΪ0
    for (int i = 0; i <= alen; i++)
        save[i][0] = 0;
    for (int i = 0; i <= blen; i++)
        save[0][i] = 0;

    for (int i = 1; i <= alen; i++) {
        for (int j = 1; j <= blen; j++) {
            if (a[i-1] == b[j-1])//����ע����
                save[i][j] = save[i-1][j-1] + 1;
            else
                save[i][j] = save[i-1][j] > save[i][j-1] ? save[i-1][j] : save[i][j-1];

        }
    }
    return save[alen][blen];
}
//������Ӵ� ��Ҫ����������
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
//�����������
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
