class Solution {
    public int solution(String dartResult) {
        dartResult += '\0';
        int answer = 0;
        int score = 0;
        int i;
        int pre = 4001;
        
        for(i=0;i<dartResult.length()-1;i++) 
        {
            if (Character.isDigit(dartResult.charAt(i)) != false)
            {
                if (Character.isDigit(dartResult.charAt(i+1)) != false) 
                {
                    score = 10;
                    i++;
                }
                else
                    score = Character.getNumericValue(dartResult.charAt(i));
            }
            else {
                if (dartResult.charAt(i) == 'S') {
                }
                else if (dartResult.charAt(i) == 'D') {
                    score = score*score;
                }
                else if (dartResult.charAt(i) == 'T') {
                    score = score*score*score;
                }
                else {
                    if (dartResult.charAt(i) == '*') {
                        if (pre == 4001)
                            score *= 2;
                        else {
                            score *= 2;
                            answer += pre;
                        }
                    }
                    else {
                        score = -score;
                    }
                }
            }
                    
            if (Character.isDigit(dartResult.charAt(i+1)) != false || i == dartResult.length()-2) {
                answer += score;
                pre = score;
            }
        }
        return answer;
    }
}