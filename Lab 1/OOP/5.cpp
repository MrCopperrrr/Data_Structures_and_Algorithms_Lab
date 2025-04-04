enum Color
{
    red,
    green,
    blue
};
enum Size
{
    small,
    medium,
    big
};

class Toy
{
protected:
    double price;

public:
    Toy(double price)
    {
        this->price = price;
    }

    virtual void printType() = 0;
    friend class ToyBox;
};

class CarToy : public Toy
{
private:
    Color color;

public:
    CarToy(double price, Color color) : Toy(price)
    {
        /*
         * STUDENT ANSWER
         */
         this->color = color;
    }

    void printType()
    {
        cout << "This is a car toy\n";
    }

    friend class ToyBox;
};

class PuzzleToy : public Toy
{
private:
    Size size;

public:
    PuzzleToy(double price, Size size) : Toy(price)
    {
        /*
         * STUDENT ANSWER
         */
         this->size = size;
    }

    void printType()
    {
        cout << "This is a puzzle toy\n";
    }

    friend class ToyBox;
};

class ToyBox
{
private:
    Toy* toyBox[5];
    int numberOfItems;

public:
    ToyBox()
    {
        /*
         * STUDENT ANSWER
         * TODO: set zero numberOfItems and nullptr toyBox
         */
         numberOfItems = 0;  // Khởi tạo số lượng đồ chơi trong hộp bằng 0
        for (int i = 0; i < 5; ++i)
        {
            toyBox[i] = nullptr;  // Khởi tạo tất cả vị trí trong mảng toyBox bằng nullptr
        }
    }
    
    int addItem(const CarToy& carToy)
    {
        /*
         * STUDENT ANSWER
         * TODO: function add a new Car toy to the box.
                 If successfully added, the function returns the current number of toys in the box. 
                 If the box is full, return -1.
         */
        if (numberOfItems < 5)
        {
            toyBox[numberOfItems++] = new CarToy(carToy);  // Thêm CarToy vào hộp và tăng số lượng đồ chơi
            return numberOfItems;  // Trả về số lượng đồ chơi hiện tại
        }
        return -1;
         
    }
    
    int addItem(const PuzzleToy& puzzleToy)
    {
        /*
         * STUDENT ANSWER
         * TODO: function add a new Puzzle toy to the box.
                 If successfully added, the function returns the current number of toys in the box. 
                 If the box is full, return -1.
         */
         if (numberOfItems < 5)
        {
            toyBox[numberOfItems++] = new PuzzleToy(puzzleToy);  // Thêm PuzzleToy vào hộp và tăng số lượng đồ chơi
            return numberOfItems;  // Trả về số lượng đồ chơi hiện tại
        }
        return -1;
    }
    
    void printBox()
    {
        for (int i = 0; i < numberOfItems; i++)
            toyBox[i]->printType();
    }
};