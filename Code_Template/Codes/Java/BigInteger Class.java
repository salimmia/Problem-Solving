import static java.lang.System.in;
import java.util.Scanner;
import java.math.BigInteger;
public class Main {
    public static void main(String[] args) 
    {
        Scanner in = new Scanner(System.in);

        int n;
        
        n = in.nextInt();

        BigInteger ci;

        ci = new BigInteger("1");

        //BigInteger b = in.nextBigInteger();
        //BigInteger carry;

        //carry = (a.multiply(b)).divide(a.gcd(b));

        for(int i=1; i<=n + 1; i++)
        {
            int temp = 4 * (i + 1) - 6;

            BigInteger tem = BigInteger.valueOf(temp);

            ci = ci.multiply(tem);
            ci = ci.divide(BigInteger.valueOf(i+1));



        }

        System.out.println(ci);

    }

}