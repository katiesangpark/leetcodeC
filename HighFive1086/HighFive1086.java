class Solution {
    public int[][] highFive(int[][] items) {
        TreeMap<Integer, PriorityQueue<Integer>> data = new TreeMap<>();
        for (int[] item : items) {
            int id = item[0], score = item[1];
            if (!data.containsKey(id)) data.put(id, new PriorityQueue<>());
            PriorityQueue<Integer> minHeap = data.get(id);
            minHeap.add(score);
            if (minHeap.size() > 5) minHeap.poll();
        }

        int[][] output = new int[data.size()][2];
        int i = 0;
        for (int id : data.keySet()) {
            PriorityQueue<Integer> pq = data.get(id);
            int sum = 0, size = pq.size();
            while (!pq.isEmpty()) sum += pq.poll();
            output[i][0] = id;
            output[i][1] = sum / size;
            i++;
        }
        return output;
    }
}