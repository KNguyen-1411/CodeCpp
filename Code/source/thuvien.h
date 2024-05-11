// tinh giai thua
auto GiaiThua(auto n) {
    return (n == 0 || n == 1) ? 1 : GiaiThua(n - 1) * n;
}
//dem so chu so
auto ChuSo(auto n) {
    auto count = 0;
    if (n == 0) {
        return 1;
    }
    while (n != 0) {
        count++;
        n /= 10;
    }
    return count;
}
//dao chu so
auto DaoSo(auto n){
    auto temp = 0;
    while (n != 0) {
        temp = temp * 10 + (n % 10);
        n /= 10;
    }
    return temp;
}
//kiem tra so nguyen to
bool IsPrime(auto n){
    auto i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            return false;
        }
        i++;
    }
    return true;
}
//ham tinh tong a den b
auto Sum_ab(auto a,auto b){
    
}