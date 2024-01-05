class Course;

class Result{
    private:
        double TX, GK, CK;
    public:
        Result();
        ~Result();
        double getTX() const;
        double getGK() const;
        double getCK() const;
        friend class Course;
};