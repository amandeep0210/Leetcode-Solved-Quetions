
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer> st = new Stack<>();
        int n = pushed.length;
        int j = 0;
        for(int i = 0; i<n; i++){
            if(st.isEmpty() || st.peek()!=popped[j]) st.push(pushed[i]);
            while(!st.isEmpty() && st.peek() == popped[j]){
                st.pop();
                j++;
            }
        }
        if(j!=n-1){
            while(j<n){
                if(st.peek()==popped[j]){
                    st.pop();
                    j++;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
}