class Solution {
    public int solution(int cacheSize, String[] cities) {
        int answer = 0;
        boolean check = false;
        boolean stop = false;
        int i, j, k;
        String[] cache = new String[cacheSize];
        int index = 0;
        
        if (cacheSize == 0)
            return 5*cities.length;
        
        for(i=0;i<cacheSize;i++) {
            for (j=0;j<i;j++) {
                if (cities[i].toUpperCase().equals(cities[j].toUpperCase()) ) {
                    stop = true;
                    break;
                }
            }
            if (stop)
                break;
            cache[index] = cities[i];
            index++;
            answer += 5;
        }
        
        for(i=index;i<cities.length;i++) {
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