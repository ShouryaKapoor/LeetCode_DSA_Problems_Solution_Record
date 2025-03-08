class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int minChanges = k; // Maximum possible changes initially
        int currentChanges = 0;

        // Count 'W' in the first window of size k
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') {
                currentChanges++;
            }
        }
        minChanges = currentChanges;

        // Slide the window across the string
        for (int i = k; i < blocks.size(); i++) {
            if (blocks[i] == 'W') currentChanges++;     // Add new block
            if (blocks[i - k] == 'W') currentChanges--; // Remove old block

            minChanges = min(minChanges, currentChanges);
        }

        return minChanges;
    }
};
