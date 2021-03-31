class Solution {
    public String solution(int n, int t, int m, int p) {
        String answer = "";
        String entry = "01";
        String temp = "";
        
        char[] alpha = {'A', 'B', 'C', 'D', 'E', 'F'};
        
        int num = 2;
        int i;
        
        while (entry.length() < t*m) {
            int tnum = num;
            
            while (tnum > 0) {
                if (tnum % n >= 10)
                    temp += alpha[tnum%n-10];
                else
                    temp += Integer.toString(tnum%n);
                tnum /= n;
            }
            StringBuffer bf = new StringBuffer(temp);
            String reverseStr = bf.reverse().toString();
            entry += reverseStr;
            
            temp = "";
            num++;
        }
        
        for(i=p-1;i<t*m;i+=m)
            answer += entry.charAt(i);
        
        return answer;
    }
}