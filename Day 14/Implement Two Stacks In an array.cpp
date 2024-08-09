class twoStacks {
  public:
    int i;
    int j;
    vector<int> arr;  // Declare the vector here

    twoStacks() : arr(210) {  // Initialize the vector in the constructor
        i = 0;
        j = 1;
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        arr[i] = x;
        i += 2;
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        arr[j] = x;
        j += 2;
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        if (i == 0) return -1;
        i = i - 2;
        return arr[i];
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        if (j == 1) return -1;
        j = j - 2;
        return arr[j];
    }
};
