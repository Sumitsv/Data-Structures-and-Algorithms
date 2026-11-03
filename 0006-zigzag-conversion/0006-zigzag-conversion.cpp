

class Solution {
public:
    string convert(string s, int numRows) {
        // Edge Case: Agar row 1 hai ya string choti hai, toh zigzag ki zaroorat hi nahi hai
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        // Har row ke liye ek string ki vector banate hain
        vector<string> rows(min(numRows, int(s.length())));
        
        int currRow = 0;
        bool goingDown = false; // Direction track karne ke liye flag

        // String ke har character par iterate karo
        for (char c : s) {
            rows[currRow] += c; // Current row mein character daal do
            
            // Agar hum first row ya last row par hain, toh direction badal do
            if (currRow == 0 || currRow == numRows - 1) {
                goingDown = !goingDown;
            }
            
            // Direction ke hisaab se agla row decide karo (neeche jaana hai ya upar)
            currRow += goingDown ? 1 : -1;
        }

        // Saari rows ko combine karke final result bana lo
        string result = "";
        for (string row : rows) {
            result += row;
        }

        return result;
    }
};