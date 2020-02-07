class Solution {
    public String removeVowels(String S) {
        StringBuilder sb = new StringBuilder();
        for (char c : S.toCharArray()) if (!isVowel(Character.toLowerCase(c))) sb.append(c);
        return sb.toString();
    }
    
    boolean isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
}