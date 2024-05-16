# Bag
Создать ещё один класс сумка для класса продукт
В этой лабораторной работе вы продолжаете разработку своей программной системы в соответствии с вариантом. Необходимо разработать ещё один или два класса, а затем в один из них добавить поле с набором (коллекцией) объектов второго. Хотя все коллекции и предназначены для хранения набора объектов, они все отличаются. Какие-то коллекции накладывают определённые ограничения на хранящиеся в коллекции элементы, другие отличаются скоростью доступа к элементам, третьи отличаются интерфейсом и т.д.

Необходимо выбрать STL-контейнер (коллекцию) , который наиболее подходит в вашем случае. Обоснуйте свой выбор. Статические и динамические массивы ([], пеми Т[SIZE]) использовать запрещено. Стандартные контейнеры безопаснее и выполняют работу с динамической памятью за вас. Если в задании сказано "список
чего-то", это не значит, что можно использовать только std::list.

Как в конструкторах, так и в остальных методах при возникновении исключительной ситуации (ошибки) методы должны генерировать исключения с помощью инструкции throw, которые обязательно должны обрабатываться где-то выше по стеку вызовов. В стандартной библиотеке С++ имеются классы для описания основных типов исключительных ситуаций. Разрабатывать свой класс исключений нужно только в самом крайнем случае. Бросать std::string в качестве исключений не нужно.
