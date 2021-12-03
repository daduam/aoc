#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> bstr;
    string str;
    while (getline(cin, str)) {
        bstr.push_back(str);
    }

    long long ogr = 0;
    long long csr = 0;
    vector<string> ogr_bstr(bstr);
    vector<string> csr_bstr(bstr);
    for (int i = 0; i < (int)bstr[0].size(); i++) {
        int ogr_cnt = ogr_bstr.size();
        int csr_cnt = csr_bstr.size();
        int ogr_freq = 0;
        int csr_freq = 0;

        for (int j = 0; j < ogr_cnt; j++) {
            if (ogr_bstr[j][i] == '1') {
                ogr_freq++;
            }
        }
        printf("%d\n", ogr_freq);
        for (int j = 0; j < csr_cnt; j++) {
            if (csr_bstr[j][i] == '0') {
                csr_freq++;
            }
        }

        vector<string> ogr_temp;
        char bit = ogr_freq >= (ogr_cnt+1)/2 ? '1' : '0';
        for (int j = 0; j < ogr_cnt; j++) {
            str = ogr_bstr[j];
            if (str[i] == bit) {
                ogr_temp.push_back(str);
            }
        }

        vector<string> csr_temp;
        bit = csr_freq <= (int)ceil(csr_cnt/2) ? '0' : '1';
        for (int j = 0; j < csr_cnt; j++) {
            str = csr_bstr[j];
            if (str[i] == bit) {
                csr_temp.push_back(str);
            }
        }

        if (ogr_temp.size() == 1) {
            ogr = bitset<64>(ogr_temp[0]).to_ullong();
        }

        if (csr_temp.size() == 1) {
            csr = bitset<64>(csr_temp[0]).to_ullong();
        }

        ogr_bstr = ogr_temp;
        csr_bstr = csr_temp;
    }

    cout << "Oxygen generator rating: " <<  ogr << endl;
    cout << "CO2 scrubber rating: " << csr << endl;
    cout << "Life support rating: " << ogr * csr << endl;
}