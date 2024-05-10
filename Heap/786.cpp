struct Fraction {
    int num_idx;
    int denom_idx;
    double numerator;
    double denominator;
};

class Compare
{
public:
    bool operator() (Fraction a, Fraction b)
    {
        // cout<<a.numerator<<' '<<a.denominator<<'\n';
        float frac_a = a.numerator / a.denominator;
        float frac_b = b.numerator / b.denominator;
        // cout<<frac_a<<' '<<frac_b<<'\n';
        return frac_a > frac_b;
    }
};

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<Fraction, vector<Fraction>, Compare> pq;
        for(int i=0; i<arr.size(); i++) {
            Fraction first(i, arr.size()-1, arr[i], arr[arr.size()-1]);
            pq.push(first);
        }
        int pops = k-1;
        while(pops--) {
            Fraction top = pq.top();
            pq.pop();
            if(top.num_idx != top.denom_idx-1) {
                Fraction denom_smaller(top.num_idx, top.denom_idx-1, arr[top.num_idx], arr[top.denom_idx-1]);
                pq.push(denom_smaller);
            }
        }
        Fraction top = pq.top();
        return {int(top.numerator), int(top.denominator)};
    }
};
