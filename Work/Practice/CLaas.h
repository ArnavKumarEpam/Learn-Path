class CLaas{
    public:
        CLaas();
        CLaas(int x);
        ~CLaas();
        void display();
    private:
        struct Impl;
        Impl * pimpl;
};