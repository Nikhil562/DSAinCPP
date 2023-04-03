class Solution {
	public int trap(int[] a) {
		int[] ngr = ngr(a);
		int[] ngl = ngl(a);
		int ans = 0;
		for (int i = 0; i < a.length ; i++) {
			if (ngl[i] != -1 && ngr[i] != -1) {
				int temp = Math.min(ngl[i], ngr[i]);
				ans +=  Math.abs(temp - a[i]);
				System.out.println(Math.abs(temp - a[i]));
			}
		}
		return ans;
	}

	public int[] ngr(int [] a) {
		int len = a.length;
		Stack<Integer> st  = new Stack<>();
		int max = -1;
		int[] ans = new int[len];
		for (int i = len - 1; i >= 0 ; i-- ) {
			if (st.isEmpty()) {
				ans[i] = -1;
			}  else {
				while (!st.isEmpty() && a[st.peek()] <= a[i]) {
					st.pop();
				}
				int temp = st.isEmpty() ? -1 : a[st.peek()];
				max = Math.max(temp, max);
				ans[i] = max > a[i] ? max : -1;
			}

			st.push(i);
		}

		return ans;
	}

	public int[] ngl(int [] a) {
		int len = a.length;
		Stack<Integer> st  = new Stack<>();
		int[] ans = new int[len];
		int min = -1;

		for (int i = 0; i < len; i++) {
			if (st.isEmpty()) {
				ans[i] = -1;
			}  else {
				while (!st.isEmpty() && a[st.peek()] <= a[i]) {
					st.pop();
				}
				int temp = st.isEmpty() ? -1 : a[st.peek()];
				min = Math.max(temp, min);
				ans[i] = min > a[i] ? min : -1;
			}

			st.push(i);
		}

		return ans;
	}
}