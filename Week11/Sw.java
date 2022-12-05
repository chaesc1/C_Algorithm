public class NutritionFacts {
    private final int servingSize;
    private final int servings;
    private final int calories;
    private final int fat;
    private final int sodium;
    private final int carbohydrate;

    public static class Builder {
        // Required parameters : 필수 인자
        private final int servingSize;
        private final int servings;

        // Optional parameters - initialized to default values : 선택적 인자는 기본값으로 초기화
        private int calories      = 0;
        private int fat           = 0;
        private int carbohydrate  = 0;
        private int sodium        = 0;

        public Builder(int servingSize, int servings) {
            this.servingSize = servingSize;
            this.servings    = servings;
        }

        public Builder calories(int val) {
            calories = val;
            return this;    // 이렇게 하면 . 으로 체인을 이어갈 수 있다.
        }
        public Builder fat(int val) {
            fat = val;
            return this;
        }
        public Builder carbohydrate(int val) {
            carbohydrate = val;
            return this;
        }
        public Builder sodium(int val) {
            sodium = val;
            return this;
        }
        public NutritionFacts build() {
            return new NutritionFacts(this);
        }
    }

    private NutritionFacts(Builder builder) {
        servingSize  = builder.servingSize;
        servings     = builder.servings;
        calories     = builder.calories;
        fat          = builder.fat;
        sodium       = builder.sodium;
        carbohydrate = builder.carbohydrate;
    }

    @Override
    public String toString() {
        return "NutritionFacts{" +
                "servingSize=" + servingSize +
                ", servings=" + servings +
                ", calories=" + calories +
                ", fat=" + fat +
                ", sodium=" + sodium +
                ", carbohydrate=" + carbohydrate +
                '}';
    }
}

public class NutritionFactsMain {
    public static void main(String[] args) {
        NutritionFacts cocaCola = new NutritionFacts
                .Builder(240, 8)    // 필수값 입력
                .calories(100)
                .sodium(35)
                .carbohydrate(27)
                .build();           // build() 가 객체를 생성해 돌려준다.

        System.out.println(cocaCola.toString());
    }
}


public class Math {

    public static double twoTime(double num) {
        return num * 2;
    }

    public static double half(double num) {
        return num / 2;
    }
}

public interface Adapter {
    public Float twiceOf(Float f);
    public Float halfOf(Float f);
}

public class AdapterImpl implements Adapter {

    @Override
    public Float twiceOf(Float f) {
        return (float) Math.twoTime(f.doubleValue());
    }

    @Override
    public Float halfOf(Float f) {
        return (float) Math.half(f.doubleValue());
    }
}

public class main {
    public static void main(String[] args) {
        Adapter adapter = new AdapterImpl();
        System.out.println(adapter.twiceOf(100f)); //200.0
        System.out.println(adapter.halfOf(50f));   //25.0
    }
}


public abstract class Character {
    public void introduce() {
        job(); 
        hp();
    }
    abstract void weapon(); abstract void armor(); abstract int hp();
}

public class Wizard extends Character { 
    public void weapon() {
            System.out.println("무기: 지팡이 \n");
    }
    public void armor() { 
        System.out.println("방어구 : 원피스");
    }
    public void job() {
        System.out.println("직업: 마법사"); 
    }
    public int Hp(){
        int hp = 240;
        System.out.println("체력 : "+hp); 
        return hp;
    }
}

public class Warrior extends Character { 
    public void weapon() {
            System.out.println("무기: 양손검 \n");
    }
    public void armor() { 
        System.out.println("방어구 : 철 갑옷");
    }
    public void job() {
        System.out.println("직업: 전사"); 
    }
    public int Hp(){
        int hp = 500;
        System.out.println("체력 : "+hp); 
        return hp;
    }
}
public class Main {
public static void main(String args[])
{
    Pokemon wizard = new Wizard(); wizard.introduce();
    Pokemon warrior = new Warrior(); warrior.introduce();
}
}

public interface IWeapon {
    public void useWeapon();
}
public class Sword implements IWeapon
 { 
    public void useWeapon() {
        System.out.println("양손검 착용"); 
    }
}

public class Staff implements IWeapon
 { 
    public void useWeapon() {
        System.out.println("지팡이 착용"); 
    }
}

public interface IArmor {
    public void wear();
}

public class Robe implements IArmor {
    public void wear()
    {
         System.out.println("로브 착용");
    }
}

public class Iron implements IArmor {
    public void wear()
    {
         System.out.println("철갑옷 착용");
    }
}

public abstract class Character { 
    public IWeapon weapon;
    public IArmor armor;
    public Character() {
    }
    public void introduce() {
        job(); 
        hp();
        weapon.useWeapon(); 
        armor.wear();
    }
    abstract void job();
    abstract int hp();
    public void setWeapon(IWeapon weapon) {
        this.weapon = weapon; 
    }
    public void setArmor(IArmor armor) 
    {
        this.armor = armor; 
    }
}

public class Wizard extends Character { 
    public Wizard() {
        weapon = new Staff();
        armor = new Robe();
    }
    void job() {
        System.out.println("직업 : 마법사"); 
        }
    int Hp(){
        int hp = 240;
        System.out.println("체력 : "+hp); 
        return hp;
    }
}

public class Warrior extends Character { 
    public Warrior() {
        weapon = new Sword();
        armor = new Iron();
    }
    void job() {
        System.out.println("직업 : 전사"); 
        }
    int Hp(){
        int hp = 500;
        System.out.println("체력 : "+hp); 
        return hp;
    }
}