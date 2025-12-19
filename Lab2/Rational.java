public class Rational {
    private int num, denom;

    public Rational(int num, int denom){
        if (denom == 0) throw new IllegalArgumentException("Denominator cannot be zero");
        int g = gcd(Math.abs(num), Math.abs(denom));
        this.num = num / g;
        this.denom = denom / g;
        if (this.denom < 0){
            this.num = -this.num;
            this.denom = -this.denom;
        }
    }
    public Rational(int num){
        this(num,1);
    }
    public Rational(){
        this(0,1);
    }
    public Rational(Rational r){
        this(r.num , r.denom);
    }
    public Rational add(Rational r){
        int n = this.num * r.denom + r.num * this.denom;
        int d = this.denom * r.denom;
        return new Rational(n, d);
    }
    public Rational sub(Rational r){
        int n = this.num * r.denom - r.num * this.denom;
        int d = this.denom * r.denom;
        return new Rational(n, d);
    }
    public Rational mul(Rational r){
        return new Rational(this.num * r.num, this.denom * r.denom);
    }
    public Rational div(Rational r){
        return new Rational(this.num * r.denom, this.denom * r.num);
    }
    public Rational addInPlace(Rational r){
        this.num = this.num * r.denom + r.num * this.denom;
        this.denom = this.denom * r.denom;
        normalize();
        return this;
    }
    public Rational subInPlace(Rational r){
        this.num = this.num * r.denom - r.num * this.denom;
        this.denom = this.denom * r.denom;
        normalize();
        return this;
    }
    public Rational mulInPlace(Rational r){
        this.num *= r.num;
        this.denom *= r.denom;
        normalize();
        return this;
    }
    public Rational divInPlace(Rational r){
        this.num *= r.denom;
        this.denom *= r.num;
        normalize();
        return this;
    }
    public Rational negate(){
        return new Rational(-this.num, this.denom);
    }
    public Rational inverse() {
        return new Rational(this.denom, this.num);
    }
    public int getNumerator() {
        return num;
    }
    public int getDenominator() {
        return denom;
    }
    public int compareTo(Rational r){
        int lhs = this.num * r.denom;
        int rhs = r.num * this.denom;
        return Integer.compare(lhs, rhs);
    }
    public boolean equals(Rational r){
        return this.compareTo(r) == 0;
    }
    public String toString() {
        if(denom ==1) return Integer.toString(num);
        return num + "/" + denom;
    }
    private void normalize(){
        int g = gcd(Math.abs(num), Math.abs(denom));
        num /= g;
        denom /= g;
        if (denom < 0){
            num = -num;
            denom = -denom;
        }
    }
    private static int gcd(int a, int b){
        if(b ==0) return a;
        return gcd(b, a % b);
    }
}
