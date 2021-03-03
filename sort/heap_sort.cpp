void heapify(int tree[], int n, int i);
void build_heap(int tree[], int n);
void heap_sort(int tree[], int n);

void build_heap(int tree[], int n) {
    int last_node = n - 1;
    int parent = (last_node - 1) / 2;
    int i;
    for (i = parent; i >= 0; i--) {
        heapify(tree, n, i);
    }
}

void heapify(int tree[], int n, int i) {
    if (i >= n) return;
    int max = i;
    int c1 = 2 * i + 1;
    int c2 = 2 * i + 2;

    if (c1 < n && tree[c1] > tree[max]) {
        max = c1;
    }
    if (c2 < n && tree[c2] > tree[max]) {
        max = c2;
    }
    if (max != i) {
        int temp = tree[max];
        tree[max] = tree[i];
        tree[i] = temp;
        heapify(tree, n, max);
    }
}

void heap_sort(int tree[], int n) {
    build_heap(tree, n);
    int i;
    for (i = n - 1; i>= 0; i--) {
        int temp = tree[i];
        tree[i] = tree[0];
        tree[0] = temp;
        heapify(tree, i, 0);
    }
}