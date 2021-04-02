class Solution {
    public String[] solution(int n, int[] arr1, int[] arr2) {
        String[] answer = {};
        answer = new String[n];
        
        int i;
        
        for (i=0;i<arr1.length;i++) {
            int uni = arr1[i] | arr2[i];
            int remain;
            String temp = "";
            
            while (uni > 0) {
                if (uni%2 == 1)
                    temp += "#";
                else
                    temp += " ";
                uni /= 2;
            }
            
            if (temp.length() < n) {
                while (temp.length() != n)
                    temp += " ";
            }
            
            StringBuffer sb = new StringBuffer(temp);
            String reverse = sb.reverse().toString();
            
            answer[i] = reverse;
        }
        return answer;
    }
}