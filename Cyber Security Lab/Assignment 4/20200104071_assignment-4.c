#include <bits/stdc++.h>
using namespace std;

string c, d, CandD;
using sBox = vector<vector<int>>;

int Box(int i, int row, int col)
{

    vector<sBox> SBox = {
        // s1
        {
            {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
            {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
            {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
            {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}},
        // s2
        {
            {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},             {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},             {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
            {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}},
        // s3
        {
            {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
            {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
            {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
            {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}},
        // s4
        {
            {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
            {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
            {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
            {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}},
        // s5
        {
            {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
            {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},             {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
            {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}},
        // s6
        {
            {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},             {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
            {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
            {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}},
        // s7
        {
            {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
            {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
            {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
            {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}},
        // s8
        {
            {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
            {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
            {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
            {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}}};

    return SBox[i][row][col];
}

string XORwithSubkey(string v, string q)
{     string res_xor;
    for (int i = 0; i < 48; i++)
    {
        if (v[i] == q[i])
        {
            res_xor += "0";
        }         else
        {
            res_xor += "1";
        }
    }
    return res_xor;
}

string E_bit_selection(string e)
{
    string f[48] = {"31", "0", "1", "2", "3", "4",
                    "3", "4", "5", "6", "7", "8",
                    "7", "8", "9", "10", "11", "12",
                    "11", "12", "13", "14", "15", "16",
                    "15", "16", "17", "18", "19", "20",
                    "19", "20", "21", "22", "23", "24",
                    "23", "24", "25", "26", "27", "28",                     "27", "28", "29", "30", "31", "0"};     string e_result, r;
    for (int i = 32; i < 64; i++)
    {         r += e[i];
    }
    for (int i = 0; i < 48; i++)
    {         string t;         t = f[i];         int x = stoi(t);         e_result += r[x];         t.clear();
    }
    return e_result;
}

string pc_2(string pc2)
{
    string f[48] = {"13", "16", "10", "23", "0", "4",
                    "2", "27", "14", "5", "20", "9",
                    "22", "18", "11", "3", "25", "7",
                    "15", "6", "26", "19", "12", "1",
                    "40", "51", "30", "36", "46", "54",
                    "29", "39", "50", "44", "32", "47",
                    "43", "48", "38", "55", "33", "52",
                    "45", "41", "49", "35", "28", "31"};

    string pc2_result;

    for (int i = 0; i < 48; i++)
    {         string t;         t = f[i];
        int x = stoi(t);
pc2_result += pc2[x];
        t.clear();
    }
    return pc2_result;
}

string leftShift(string cdls, int n)
{     string res_cls, cls, dls;     int cd = 0, ce = 0;     // int no = stoi(n);

    for (int i = 0; i < cdls.length(); i++)
    {         if (i < 28)
        {
            cls += cdls[i];
        }         else
        {
            dls += cdls[i];
        }
    }

    if (n == 0 || n == 1 || n == 8 || n == 15)
    {
        char temp1 = cls[0];         char temp2 = cls[1];         char temp3 = dls[0];         char temp4 = dls[1];
        for (int i = 0; i < 28; i++)
        {             if (i < 27)
            {                 cls[i] = cls[i + 1];
                dls[i] = dls[i + 1];
            }
            else if (i == 27)
            {
                cls[i] = temp1;
                dls[i] = temp3;
            } }
    }     else
    {
        for (int i = 0; i < 2; i++)
        {
            char temp1 = cls[0];             char temp2 = cls[1];             char temp3 = dls[0];             char temp4 = dls[1];
            for (int i = 0; i < 28; i++)
            {
                if (i < 27)
                {
                    cls[i] = cls[i + 1];
                    dls[i] = dls[i + 1];
                }
                else if (i == 27)
                {
                    cls[i] = temp1;
                    dls[i] = temp3;
                }
            }
        }
    }

    return res_cls = cls + dls;
}

string pc_1(string pc)
{
    string f[56] = {"56", "48", "40", "32", "24", "16", "8", "0",
                    "57", "49", "41", "33", "25", "17", "9",
                    "1", "58", "50", "42", "34", "26", "18",
                    "10", "2", "59", "51", "43", "35", "62",
                    "54", "46", "38", "30", "22", "14", "6",
                    "61", "53", "45", "37", "29", "21", "13",
                    "5", "60", "52", "44", "36", "28", "20",                     "12", "4", "27", "19", "11", "3"};     for (int i = 0; i < 56; i++)
    {
        if (i <= 27)
{
            string t;             t = f[i];             int x = stoi(t);             c += pc[x];             t.clear();         }         else         {             string t;             t = f[i];             int x = stoi(t);             d += pc[x];             t.clear();
        }
    }
    CandD = c + d;
    return c, d, CandD;
}

string ip_cal(string ip)
{
    string f[64] = {"57", "49", "41", "33", "25", "17", "9", "1",                     "59", "51", "43", "35", "27", "19", "11", "3",
                    "61", "53", "45", "37", "29", "21", "13", "5",
                    "63", "55", "47", "39", "31", "23", "15", "7",
                    "56", "48", "40", "32", "24", "16", "08", "0",
                    "58", "50", "42", "34", "26", "18", "10", "2",
                    "60", "52", "44", "36", "28", "20", "12", "4",                     "62", "54", "46", "38", "30", "22", "14", "6"};     string ip_result;

    for (int i = 0; i < 64; i++)
    {         string t;         t = f[i];         int x = stoi(t);         ip_result += ip[x];         t.clear();     }
    return ip_result;
}

string convertKeyToBinary(int k[])
{     string t, rev;
    for (int i = 0; i < 8; i++)
    {         int x = k[i], ct = 0;
        while (x > 0)
        {             ct++;
            if (x % 2 != 0)
            {                 t += '1';                 x = x / 2;             }             else             {                 t += '0';                 x = x / 2;
            }
        }         if (ct < 8)
        {
            for (int j = 0; j < 8 - ct; j++)
            {                 t += '0';
            }
        }

        reverse(t.begin(), t.end());         rev += t;
        t.clear();
    }
    return rev;
}

string convertToBinary(string s)
{     int length = s.length();
    string t, rev;

    for (int i = 0; i < length; i++)
{
        int x = s[i], ct = 0;
        while (x > 0)
        {             ct++;             if (x % 2 != 0)
            {                 t += '1';                 x = x / 2;             }             else             {                 t += '0';                 x = x / 2;
            }
        }

        for (int j = 0; j < 8 - ct; j++)
        {             t += '0';
        }
        reverse(t.begin(), t.end());         rev += t;
        t.clear();
    }
    if (rev.length() < 64)
    {
        int y = 64 - rev.length();
        for (int i = 0; i < y; i++)
        {
            if (rev.length() < 64)
            {
                for (int k = 0; k < 8; k++)
                {                     if (k == 0)
                    {                         rev += '1';                     }                     else                     {                         rev += '0';
                    }
                }
            }
        }
    }     else
    {
        while (rev.length() % 64 != 0)
        {
            for (int k = 0; k < 8; k++)
            {                 if (k == 0)
                {                     rev += '1';
                }                 else                 {                     rev += '0';
                }
            }
        }
    }

    return rev;
}

int giveRow(string (&xor_res_arr)[6])
{
    // int *row = new int[8];     // int ro = 0;
    int row;

    if (xor_res_arr[0] == "0" && xor_res_arr[5] == "0")
    {
        row = 0;
        return row;
    }
    if (xor_res_arr[0] == "0" && xor_res_arr[5] == "1")
    {
        row = 1;
        return row;
    }
    if (xor_res_arr[0] == "1" && xor_res_arr[5] == "0")
{
        row = 2;
        return row;
    }
    if (xor_res_arr[0] == "1" && xor_res_arr[5] == "1")
    {
        row = 3;
        return row;
    }
    return 0;
}

int giveColumn(string (&xor_res_arr)[6])
{
    // int *col = new int[16];
    // int co = 0;
    int col;

    if (xor_res_arr[1] == "0" && xor_res_arr[2] == "0" && xor_res_arr[3] == "0" && xor_res_arr[4] == "0")
    {         col = 0;
        return col;
    }
    if (xor_res_arr[1] == "0" && xor_res_arr[2] == "0" && xor_res_arr[3] == "0" && xor_res_arr[4] == "1")
    {         col = 1;
        return col;
    }
    if (xor_res_arr[1] == "0" && xor_res_arr[2] == "0" && xor_res_arr[3] == "1" && xor_res_arr[4] == "0")
    {         col = 2;
        return col;
    }
    if (xor_res_arr[1] == "0" && xor_res_arr[2] == "0" && xor_res_arr[3] == "1" && xor_res_arr[4] == "1")
    {         col = 3;
        return col;
    }
    if (xor_res_arr[1] == "0" && xor_res_arr[2] == "1" && xor_res_arr[3] == "0" && xor_res_arr[4] == "")
    {         col = 4;
        return col;
    }
    if (xor_res_arr[1] == "0" && xor_res_arr[2] == "1" && xor_res_arr[3] == "0" && xor_res_arr[4] == "1")
    {         col = 5;
        return col;
    }
    if (xor_res_arr[1] == "0" && xor_res_arr[2] == "1" && xor_res_arr[3] == "1" && xor_res_arr[4] == "0")
    {         col = 6;
        return col;
    }
    if (xor_res_arr[1] == "0" && xor_res_arr[2] == "1" && xor_res_arr[3] == "1" && xor_res_arr[4] == "1")
    {         col = 7;
        return col;
    }
    if (xor_res_arr[1] == "1" && xor_res_arr[2] == "0" && xor_res_arr[3] == "0" && xor_res_arr[4] == "0")
    {         col = 8;
        return col;
    }
    if (xor_res_arr[1] == "1" && xor_res_arr[2] == "0" && xor_res_arr[3] == "0" && xor_res_arr[4] == "1")
    {         col = 9;
        return col;
    }
    if (xor_res_arr[1] == "1" && xor_res_arr[2] == "0" && xor_res_arr[3] == "1" && xor_res_arr[4] == "0")
    {         col = 10;
        return col;
}
    if (xor_res_arr[1] == "1" && xor_res_arr[2] == "0" && xor_res_arr[3] == "1" && xor_res_arr[4] == "1")
    {         col = 11;
        return col;
    }
    if (xor_res_arr[1] == "1" && xor_res_arr[2] == "1" && xor_res_arr[3] == "0" && xor_res_arr[4] == "0")
    {         col = 12;
        return col;
    }
    if (xor_res_arr[1] == "1" && xor_res_arr[2] == "1" && xor_res_arr[3] == "0" && xor_res_arr[4] == "1")
    {         col = 13;
        return col;
    }
    if (xor_res_arr[1] == "1" && xor_res_arr[2] == "1" && xor_res_arr[3] == "1" && xor_res_arr[4] == "0")
    {         col = 14;
        return col;
    }
    if (xor_res_arr[1] == "1" && xor_res_arr[2] == "1" && xor_res_arr[3] == "1" && xor_res_arr[4] == "1")
    {         col = 15;
        return col;
    }
    return 0;
}

string convetSValues(int x[])
{
    string t, rev;
    for (int i = 0; i < 8; i++)
    {
        int k = x[i], ct = 0;
        while (k > 0)
        {             ct++;             if (k % 2 != 0)
            {                 t += '1';
                k = k / 2;
            }             else             {                 t += '0';                 k = k / 2;
            }
        }         if (ct < 4)
        {
            for (int j = 0; j < 4 - ct; j++)
            {                 t += '0';
            }
        }

        reverse(t.begin(), t.end());         rev += t;
        t.clear();
    }
    return rev;
}

string SBoxPermutation(string sp)
{

    string f[32] = {
        "15",
        "6",
        "19",
        "20",
        "28",
        "11",
        "27",
        "16",
        "0",
        "14",
        "22",
        "25",
        "4",
        "17",
        "30",
        "9",
        "1",
        "7",
        "23",
        "13",
        "31",
        "26",
        "2",
        "8",
        "18",
        "12",
        "29",
        "5",
        "21",
        "10",
        "3",
        "24",
    };

    string s_per_res;

    for (int i = 0; i < 32; i++)
    {         string t;         t = f[i];         int x = stoi(t);         s_per_res += sp[x];         t.clear();
    }
    return s_per_res;
}

string XORLeftandRight(string first, string second)
{     string res_xor, cls;
    int cd = 0, ce = 0;

    for (int i = 0; i < 32; i++)
    {
        cls += first[i];
    }

    for (int i = 0; i < 32; i++)
    {
        if (cls[i] == second[i])
        {
            res_xor += "0";
        }         else
        {
            res_xor += "1";
        }
    }
    return res_xor;
}

string afterXORLR(string first, string second)
{
    string res_afterXORLR;
    for (int i = 32; i < 64; i++)
    {
        res_afterXORLR += first[i];
    }
    for (int i = 0; i < 32; i++)
    {
        res_afterXORLR += second[i];
    }

    return res_afterXORLR;
}

string InverseInitialPermutation(string b)
{
    string f[64] = {"39", "7", "47", "15", "55", "23", "63", "31",
                    "38", "6", "46", "14", "54", "22", "62", "30",
                    "37", "5", "45", "13", "53", "21", "61", "29",
                    "36", "4", "44", "12", "52", "20", "60", "28",
                    "35", "3", "43", "11", "51", "19", "59", "27",
                    "34", "2", "42", "10", "50", "18", "58", "26",
                    "33", "1", "41", "9", "49", "17", "57", "25",
                    "32", "0", "40", "8", "48", "16", "56", "24"};

    string InverseInitialPermutationRes;

    for (int i = 0; i < 64; i++)
    {         string t;         t = f[i];
        int x = stoi(t);
        InverseInitialPermutationRes += b[x];
        t.clear();
    }
    return InverseInitialPermutationRes;
}

string swap(string s)
{     string swap;

    for (int i = 32; i < 64; i++)
    {
        swap += s[i];
    }
    for (int i = 0; i < 32; i++)
    {
        swap += s[i];
    }
    return swap;
}

string xorWithPlaintext(string first, string second)
{
    string res_xor;

    for (int i = 0; i < 32; i++)
    {
        if (first[i] == second[i])
        {
            res_xor += "0";
        }         else
        {
res_xor += "1";
        }
    }
    return res_xor;
}

void Decryption(string ivAfterBinary, string plaintextAftBin, string keyAfterBinary, string cipherText)
{
    string ip_result = ip_cal(ivAfterBinary);
    // string ip_result = ip_cal(plaintextAftBin);

    string pc_1_result = pc_1(keyAfterBinary);

    string subKeys[16], g;

    for (int i = 0; i < 16; i++)
    {
        if (i == 0)
        {
            subKeys[i] = leftShift(pc_1_result, i);
            g = subKeys[i];
        }         else
        {
            subKeys[i] = leftShift(g, i);             g = subKeys[i];
        }
    }

    string pc_2_result[16];
    for (int i = 0; i < 16; i++)
    {
        pc_2_result[i] = pc_2(subKeys[i]);
    }
    cout << "All keys: " << endl;
    for (int i = 0; i < 16; i++)
    {
        cout << pc_2_result[i] << endl;
    }
    cout << endl;     string SvaluesAfterBinary;     string SBoxPermuteResult;     string XORLeftandRightResult;     string main_s_permute;     string afterXORLRResult[16];
    string e_result;     string xor_result;     string xor_res_arr[8][6];     string rev_S_permatution[8][4];
    int sbox_result[8];     int row1[8], col1[8];     int t = 15;     string ip_result2 = ip_cal(ivAfterBinary);
    for (int i = 0; i < 16; i++)
    {

        if (i == 0)
        {
            e_result = E_bit_selection(ip_result2);

            int p = 0;

            xor_result = XORwithSubkey(e_result, pc_2_result[i]);             t--;

            for (int j = 0; j < 8; j++)
            {
                for (int k = 0; k < 6; k++)
                {
                    xor_res_arr[j][k] = xor_result[p];
                    p++;
                }
            }

            for (int u = 0; u < 8; u++)
            {
                row1[u] = giveRow(xor_res_arr[u]);
            }
            for (int u = 0; u < 16; u++)
            {
                col1[u] = giveColumn(xor_res_arr[u]);
            }

for (int l = 0; l < 8; l++)
            {
                sbox_result[l] = Box(l, row1[l], col1[l]);
            }

            SvaluesAfterBinary = convetSValues(sbox_result);

            SBoxPermuteResult = SBoxPermutation(SvaluesAfterBinary);

            int b = 0;             for (int x = 0; x < 8; x++)
            {
                for (int y = 0; y < 4; y++)
                {
                    rev_S_permatution[x][y] = SBoxPermuteResult[b];                     b++;
                }
            }
            for (int c = 0; c < 4; c++)
            {
                for (int r = 7; r <= 0; r--)
                {
                    main_s_permute += rev_S_permatution[r][c];
                }
            }

            XORLeftandRightResult = XORLeftandRight(ip_result, main_s_permute);

            afterXORLRResult[i] = afterXORLR(ip_result2, XORLeftandRightResult);             cout << "Round (";             cout << i + 1;
            cout << "): ";             cout << afterXORLRResult[i] << endl;
        }         else
        {
            e_result = E_bit_selection(afterXORLRResult[i - 1]);

            int p = 0;

            xor_result = XORwithSubkey(e_result, pc_2_result[i]);             t--;

            for (int j = 0; j < 8; j++)
            {
                for (int k = 0; k < 6; k++)
                {
                    xor_res_arr[j][k] = xor_result[p];
                    p++;
                }
            }

            for (int u = 0; u < 8; u++)
            {
                row1[u] = giveRow(xor_res_arr[u]);
            }
            for (int u = 0; u < 16; u++)
            {
                col1[u] = giveColumn(xor_res_arr[u]);
            }

            for (int l = 0; l < 8; l++)
            {
                sbox_result[l] = Box(l, row1[l], col1[l]);
            }
            SvaluesAfterBinary = convetSValues(sbox_result);

            SBoxPermuteResult = SBoxPermutation(SvaluesAfterBinary);

            int b = 0;             for (int x = 0; x < 8; x++)
            {
                for (int y = 0; y < 4; y++)
                {
                    rev_S_permatution[x][y] = SBoxPermuteResult[b];                     b++;
                }
            }
            for (int c = 0; c < 4; c++)
            {
                for (int r = 7; r <= 0; r--)
                {
                    main_s_permute += rev_S_permatution[r][c];
                }
}

            XORLeftandRightResult = XORLeftandRight(afterXORLRResult[i - 1],
SBoxPermuteResult);

            afterXORLRResult[i] = afterXORLR(afterXORLRResult[i - 1], XORLeftandRightResult);             cout << "Round (";             cout << i + 1;
            cout << "): ";             cout << afterXORLRResult[i] << endl;
        }
    }
    string swapResult2 = swap(afterXORLRResult[15]);     string InverseInitialPermutationResult2 = InverseInitialPermutation(afterXORLRResult[15]);     cout << endl;     string plainText = xorWithPlaintext(InverseInitialPermutationResult2, cipherText);     cout << "Final plaint text: ";     cout << plainText;     cout << endl;     cout << endl;
}

string Encryption(string ivAfterBinary, string plaintextAftBin, string keyAfterBinary)
{
    string ip_result = ip_cal(ivAfterBinary);
    // string ip_result = ip_cal(plaintextAftBin);

    string pc_1_result = pc_1(keyAfterBinary);

    string subKeys[16], g;

    for (int i = 0; i < 16; i++)
    {
        if (i == 0)
        {
            subKeys[i] = leftShift(pc_1_result, i);
            g = subKeys[i];
        }         else
        {
            subKeys[i] = leftShift(g, i);             g = subKeys[i];
        }
    }

    string pc_2_result[16];
    for (int i = 0; i < 16; i++)
    {
        pc_2_result[i] = pc_2(subKeys[i]);
    }
    cout << "All keys: " << endl;
    for (int i = 0; i < 16; i++)
    {
        cout << pc_2_result[i] << endl;
    }
    cout << endl;     string SvaluesAfterBinary;     string SBoxPermuteResult;     string XORLeftandRightResult;     string main_s_permute;     string afterXORLRResult[16];
    string e_result;     string xor_result;     string xor_res_arr[8][6];     string rev_S_permatution[8][4];
    int sbox_result[8];     int row1[8], col1[8];     int t = 15;

    for (int i = 0; i < 16; i++)
    {

        if (i == 0)
        {
            e_result = E_bit_selection(ip_result);

            int p = 0;

            xor_result = XORwithSubkey(e_result, pc_2_result[i]);

            for (int j = 0; j < 8; j++)
            {
                for (int k = 0; k < 6; k++)
                {
                    xor_res_arr[j][k] = xor_result[p];                     p++;
                }
            }

            for (int u = 0; u < 8; u++)
            {
                row1[u] = giveRow(xor_res_arr[u]);
            }
            for (int u = 0; u < 8; u++)
            {
                col1[u] = giveColumn(xor_res_arr[u]);
            }

            for (int l = 0; l < 8; l++)
            {
                sbox_result[l] = Box(l, row1[l], col1[l]);
            }

            SvaluesAfterBinary = convetSValues(sbox_result);

            SBoxPermuteResult = SBoxPermutation(SvaluesAfterBinary);             int b = 0;             for (int x = 0; x < 8; x++)
            {
                for (int y = 0; y < 4; y++)
                {
                    rev_S_permatution[x][y] = SBoxPermuteResult[b];                     b++;
                }
            }
            for (int c = 0; c < 4; c++)
            {
                for (int r = 7; r >= 0; r--)
                {
                    main_s_permute += rev_S_permatution[r][c];
                }
            }
            XORLeftandRightResult = XORLeftandRight(ip_result, main_s_permute);

            afterXORLRResult[i] = afterXORLR(ip_result, XORLeftandRightResult);             cout << "Round (";
            cout << i + 1;
            cout << "): ";             cout << afterXORLRResult[i] << endl;
        }         else
        {
            e_result = E_bit_selection(afterXORLRResult[i - 1]);

            int p = 0;

            xor_result = XORwithSubkey(e_result, pc_2_result[i]);

            for (int j = 0; j < 8; j++)
            {
                for (int k = 0; k < 6; k++)
                {
                    xor_res_arr[j][k] = xor_result[p];
                    p++;
                }
            }

            for (int u = 0; u < 8; u++)
            {
                row1[u] = giveRow(xor_res_arr[u]);
            }
            for (int u = 0; u < 8; u++)
            {
                col1[u] = giveColumn(xor_res_arr[u]);
            }

            for (int l = 0; l < 8; l++)
            {
                sbox_result[l] = Box(l, row1[l], col1[l]);
            }
            SvaluesAfterBinary = convetSValues(sbox_result);

            SBoxPermuteResult = SBoxPermutation(SvaluesAfterBinary);

            int b = 0;             for (int x = 0; x < 8; x++)
            {
                for (int y = 0; y < 4; y++)
                {
                    rev_S_permatution[x][y] = SBoxPermuteResult[b];                     b++;
                }
            }
            for (int c = 0; c < 4; c++)
            {
                for (int r = 7; r <= 0; r--)
                {
                    main_s_permute += rev_S_permatution[r][c];
                }
            }
            XORLeftandRightResult = XORLeftandRight(ip_result, main_s_permute);

            afterXORLRResult[i] = afterXORLR(ip_result, XORLeftandRightResult);

            XORLeftandRightResult = XORLeftandRight(afterXORLRResult[i - 1],
SBoxPermuteResult);

            afterXORLRResult[i] = afterXORLR(afterXORLRResult[i - 1], XORLeftandRightResult);             cout << "Round (";             cout << i + 1;
            cout << "): ";             cout << afterXORLRResult[i] << endl;
        }
    }
    string swapResult = swap(afterXORLRResult[15]);     string InverseInitialPermutationResult = InverseInitialPermutation(afterXORLRResult[15]);     cout << endl;     string cipherText = xorWithPlaintext(InverseInitialPermutationResult, plaintextAftBin);     cout << "Final cipher text: ";     cout << cipherText;     cout << endl;     cout << endl;

    return cipherText;
}

int main()
{
    cout << "Enter Initial Vector: ";
    int iv[8], c;     for (int i = 0; i < 8; i++)
    {         cin >> c;         iv[i] = c;
    }
    string ivAfterBinary = convertKeyToBinary(iv);

    string s;     cout << "PlainText: ";
    cin >> s;     string plaintextAftBin = convertToBinary(s);

    cout << "Enter Key: ";     int key[8], b;
    for (int i = 0; i < 8; i++)
    {         cin >> b;
        key[i] = b;
    }
    string keyAfterBinary = convertKeyToBinary(key);

    cout << endl;

    int noOfBlock, ct = 0, j = 0;     string noOfPlaintext[100];
    noOfBlock = (plaintextAftBin.length() / 64);

    for (int i = 0; i < noOfBlock; i++)
    {
        for (; j < plaintextAftBin.length();)
        {
            noOfPlaintext[i] += plaintextAftBin[j];             int p = j + 1;
            j++;
            if ((p) % 64 == 0)
            {                 break;
            }
        }
    }

    string a = Encryption(ivAfterBinary, plaintextAftBin, keyAfterBinary);

    Decryption(ivAfterBinary, plaintextAftBin, keyAfterBinary, a);
}

