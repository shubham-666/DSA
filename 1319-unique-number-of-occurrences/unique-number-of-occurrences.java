class Solution {
public boolean uniqueOccurrences(int[] arr) {
HashMap<Integer, Integer> freq = new HashMap<>();

    for(int i =0 ; i< arr.length ; i++){
        if(freq.containsKey(arr[i])) freq.put(arr[i] , 1 + freq.get(arr[i]) );
        else freq.put(arr[i], 1);
    }

   HashMap<Integer, Integer> freq2 = new HashMap<>();


   for(int i : freq.values()){
        if(freq2.containsKey(i)) freq2.put(i , 1 + freq2.get(i) );
        else freq2.put(i, 1);
    }

    for(int i : freq2.values()){
        if(i > 1) return false;
    }

    return true;
}
}