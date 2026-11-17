class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        
        int i, j, n = matrix.size(), m = matrix[0].size();
        priority_queue< int, vector<int>, greater<int> >pq; // min heap of  size k for kth largest
        
		// xor all the rows 
        for(i = 0; i < n; i++)
        {
            for(j = 1; j < m; j++)
            {
                matrix[i][j] = matrix[i][j-1] ^ matrix[i][j];
            }
        }
        
		// xor all the coloumns 
        for(i = 0; i < m; i++)
        {
            for(j = 1; j < n; j++)
            {
                matrix[j][i] = matrix[j-1][i] ^ matrix[j][i];
            }
        }
        
		// travese xor matrix
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                if(pq.size() < k) // heap size is less than k push into heap
                    pq.push(matrix[i][j]);
                else
                {
                   if(matrix[i][j] > pq.top())  // if heap is full , then check next ele with heap top , if top is less than curr , pop them and add curr into heap
                   {
                       pq.pop();
                       pq.push(matrix[i][j]);
                   }
                }
            }
        }
        
        return pq.top(); // return top of heap ( top always contain kth largest ele)
    }
};