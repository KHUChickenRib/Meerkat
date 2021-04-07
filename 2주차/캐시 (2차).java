class Solution {
    public int solution(int cacheSize, String[] cities) {
        int answer = 0;
        boolean check = false;
        int i, j, k;
        String[] cache = new String[cacheSize];
        int index = 0;
        
        if (cacheSize == 0)
            return 5*cities.length;
        
        for(i=0;i<cities.length;i++) {
            for(j=0;j<index;j++) {
                if (cities[i].toUpperCase().equals(cache[j].toUpperCase())) {
                    check = true;
                    break;
                }
            }
            
            if(check) {
                answer += 1;
                for(k=j;k<index-1;k++)
                    cache[k] = cache[k+1];
                cache[index-1] = cities[i];
            }
            else {
                answer += 5;
                
                if (index < cacheSize)
                {
                    cache[index] = cities[i];
                    index++;
                }
                else {
                    for(k=1;k<index;k++)
                        cache[k-1] = cache[k];
                    cache[index-1] = cities[i];
                }
            }
            check = false;
        }
        
        return answer;
    }
}