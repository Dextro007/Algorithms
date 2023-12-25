// Usual method to compute fibnonacci

class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n) 
    {
	    vector<long long> result;
	    long long a = 1;
	    long long b = 1;
	    long long c = 0;
	    result.push_back(a);
	    if(n == 1)
		    return result;
	    result.push_back(b);
	    for(long long i  = 2; i<n; i++){
		    c = a+b;
		    a = b;
		    b = c;
		    result.push_back(c);
    	}
	    return result;
    }
};
