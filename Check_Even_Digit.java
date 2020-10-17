public static int evenDigits(int n) {
    if (n == 0) {
        return 0;
    } else {
        int num = n % 10;
        if (num % 2 == 0) {
            return num + evenDigits(n / 10) * 10;
        } else {
            return evenDigits(n / 10);
        }
    }
}
