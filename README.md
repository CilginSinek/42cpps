# 42 C++ Piscine (cpp_00 - cpp_04)

Bu repository 42 okulunun C++ piscine (yoğun kursu) projelerini içermektedir. Projeler, temel C++ konseptlerinden nesne yönelimli programlamaya kadar uzanan kademeli bir öğrenme yolculuğunu sunar.

## 📋 İçindekiler

- [Proje Yapısı](#proje-yapısı)
- [cpp_00: Namespace, class, member functions, stdio stream (BONUS)](#-cpp_00-namespace-class-member-functions-stdio-stream-bonus)
- [cpp_01: Memory allocation, references, pointers to members (BONUS)](#-cpp_01-memory-allocation-references-pointers-to-members-bonus)
- [cpp_02: Ad-hoc polymorphism, operator overloading, orthodox canonical class form (BONUS)](#-cpp_02-ad-hoc-polymorphism-operator-overloading-orthodox-canonical-class-form-bonus)
- [cpp_03: Inheritance (BONUS)](#-cpp_03-inheritance-bonus)
- [cpp_04: Subtype polymorphism, virtual functions, abstract classes (MANDATORY)](#-cpp_04-subtype-polymorphism-virtual-functions-abstract-classes-mandatory)

---

## 🏗️ Proje Yapısı

```
42cpps/
├── cpp_00/
│   ├── ex00/  (Megaphone)
│   ├── ex01/  (PhoneBook)
│   └── ex02/  (Account)
├── cpp_01/
│   ├── ex00/  (Zombie - newZombie & randomChump)
│   ├── ex01/  (Zombie - zombieHorde)
│   ├── ex02/  (This)
│   ├── ex03/  (HumanA & HumanB with Weapon)
│   ├── ex04/  (sed replacement)
│   ├── ex05/  (Harl Filter)
│   └── ex06/  (Harl Filter with switch)
├── cpp_02/
│   ├── ex00/  (Fixed - Orthodox Canonical Form)
│   ├── ex01/  (Fixed - Operators)
│   ├── ex02/  (Fixed - Comparison & Arithmetic Operators)
│   └── ex03/  (Fixed & Point - BSP Function)
├── cpp_03/
│   ├── ex00/  (ClapTrap)
│   ├── ex01/  (ScavTrap inherits from ClapTrap)
│   ├── ex02/  (FragTrap inherits from ClapTrap)
│   └── ex03/  (DiamondTrap - Multiple Inheritance)
└── cpp_04/
    ├── ex00/  (Virtual Functions - Animal, Cat, Dog)
    ├── ex01/  (Deep Copy - Brain allocation)
    └── ex02/  (Pure Virtual Functions - Abstract Animal)
```

---

## 🎯 Modüllerin Detaylı Açıklaması

---

### 🎁 cpp_00: Namespace, class, member functions, stdio stream [BONUS]

**Amaç**: Temel C++ kavramlarını öğrenmek - class yapısı, member fonksiyonlar ve I/O işlemleri.

#### **ex00: Megaphone**
- **Konu**: Argv işleme, toupper() fonksiyonu
- **Dosyalar**: `megaphone.cpp`
- **Açıklama**: Komut satırı argümanlarını büyük harfe çeviren ve ekrana yazdıran basit program
- **Çıktı**: "* LOUD AND UNBEARABLE FEEDBACK NOISE *" veya girilen metni büyük harfle ekrana yazdırır

#### **ex01: PhoneBook**
- **Konu**: Class tasarımı, member fonksiyonlar, private/public
- **Dosyalar**: `PhoneBook.hpp`, `PhoneBook.cpp`, `Phone.hpp`, `Phone.cpp`, `main.cpp`
- **Sınıflar**:
  - `Phone`: Telefon defteri girişi (isim, soyisim, takma ad, etc.)
  - `PhoneBook`: En fazla 8 telefon kaydı tutar (circular buffer)
- **İşlevler**:
  - `add`: Yeni kontakt ekle
  - `search`: Kontakt ara ve göster
  - `exit`: Programdan çık

#### **ex02: Account**
- **Konu**: Static member variables, static member functions
- **Dosyalar**: `Account.hpp`, `Account.cpp`, `tests.cpp`
- **Sınıf**: `Account` - Banka hesabı simülasyonu
- **Özellikler**:
  - İşlem geçmişi (deposits, withdrawals)
  - Toplam hesap sayısı ve toplam tutar takibi
  - Timestamp outputu

---

### 🎁 cpp_01: Memory allocation, references, pointers to members [BONUS]

**Amaç**: Bellek yönetimi, pointers ve referansları öğrenmek. New/delete kullanımı.

#### **ex00: Zombie - newZombie & randomChump**
- **Konu**: Pointer allokasyonu, bellek yönetimi
- **Dosyalar**: `Zombie.hpp`, `Zombie.cpp`, `newZombie.cpp`, `randomChump.cpp`, `main.cpp`
- **Sınıf**: `Zombie` - Zombie nesne simülasyonu
- **Fonksiyonlar**:
  - `newZombie()`: Heap'te zombie oluştur (pointer döndür)
  - `randomChump()`: Stack'te zombie oluştur (çıktı sonunda yok ol)
  - `announce()`: Zombie "ad...BRAIIIIINNNNSSSS" çıktı ver

#### **ex01: Zombie Horde**
- **Konu**: Array allocation, delete[] kullanması
- **Dosyalar**: `Zombie.hpp`, `Zombie.cpp`, `zombieHorde.cpp`, `main.cpp`
- **Fonksiyon**:
  - `zombieHorde()`: N tane zombie'nin array'ini oluştur ve tümünü announce ettir

#### **ex02: This**
- **Konu**: `this` pointer, reference döndüren fonksiyonlar
- **Dosyalar**: `main.cpp`
- **Açıklama**: Reference ve pointer karşılaştırması, this pointer kullanımı

#### **ex03: HumanA & HumanB with Weapon**
- **Konu**: Reference vs Pointer, Composition
- **Dosyalar**: `Weapon.hpp`, `Weapon.cpp`, `HumanA.hpp`, `HumanA.cpp`, `HumanB.hpp`, `HumanB.cpp`, `main.cpp`
- **Sınıflar**:
  - `Weapon`: İsim ve hasarı tutan sınıf
  - `HumanA`: Silahı reference ile tutması (initializer list)
  - `HumanB`: Silahı pointer ile tutması (optional)
- **Fark**: Reference vs Pointer davranışları ve null check

#### **ex04: sed replacement**
- **Konu**: File I/O, string bulma ve değiştirme
- **Dosyalar**: `main.cpp`
- **İşlevsellik**: `./replace file s1 s2` - dosyada s1'i s2 ile değiştir
- **Detaylar**: Her occurrence'ı değiştir, output dosya adı filename.replace olsun

#### **ex05: Harl Filter - Verbose Mode**
- **Konu**: Function pointers, member function pointers
- **Dosyalar**: `Harl.hpp`, `Harl.cpp`, `main.cpp`
- **Sınıf**: `Harl` - Loglama sistemesi
- **Fonksiyonlar**:
  - `debug()`, `info()`, `warning()`, `error()` - farklı log seviyeleri
  - `complain()` - string parametresi alarak uygun seviye fonksiyonunu çağır
- **Özellik**: Function pointers kullanarak dinamik dispatch

#### **ex06: Harl Filter with Switch**
- **Konu**: Switch statement, function array'lar
- **Dosyalar**: `Harl.hpp`, `Harl.cpp`, `main.cpp`
- **Açıklama**: ex05'in switch statement versiyonu
- **Özellik**: Seviye altındaki tüm mesajları yazdırır (fall-through)

---

### 🎁 cpp_02: Ad-hoc polymorphism, operator overloading, orthodox canonical class form [BONUS]

**Amaç**: Operator overloading ve orthodox canonical form (OCF) öğrenmek.

#### **ex00: Fixed - Orthodox Canonical Form**
- **Konu**: OCF (default constructor, copy constructor, assignment operator, destructor)
- **Dosyalar**: `Fixed.hpp`, `Fixed.cpp`, `main.cpp`
- **Sınıf**: `Fixed` - Sabit noktalı sayı (fixed-point number)
- **Özellikler**:
  - 8 bit kesirli kısım
  - `getRawBits()`, `setRawBits()`
  - Constructor/copy/assignment/destructor tümü explicit
  - Output: Constructor/Destructor çağrılarını log et

#### **ex01: Fixed - Operators (Comparison & Arithmetic)**
- **Konu**: Operator overloading (arithmetic ve comparison)
- **Dosyalar**: `Fixed.hpp`, `Fixed.cpp`, `main.cpp`
- **Operatörler**:
  - Comparison: `>`, `<`, `>=`, `<=`, `==`, `!=`
  - Arithmetic: `+`, `-`, `*`, `/`
  - Increment/Decrement: `++`, `--` (pre ve post)
  - Min/Max static functions

#### **ex02: Fixed - Float/Int Conversion**
- **Konu**: Type conversion, constructor overloading
- **Dosyalar**: `Fixed.hpp`, `Fixed.cpp`, `main.cpp`
- **Yetenekler**:
  - `Fixed(float)` - Float'dan dönüştür
  - `Fixed(int)` - Int'tan dönüştür
  - `toFloat()` - Float'a dönüştür
  - `toInt()` - Int'a dönüştür
  - Output operatörü `<<`

#### **ex03: Fixed & Point - BSP Function**
- **Konu**: Computational geometry, triangle içi nokta tespiti
- **Dosyalar**: `Fixed.hpp`, `Fixed.cpp`, `Point.hpp`, `Point.cpp`, `bsp.cpp`, `main.cpp`
- **Sınıflar**:
  - `Point` - x, y koordinatları (immutable)
- **Fonksiyon**: `bsp()` - Nokta üçgenin içinde mi? (barycentric coordinates)

---

### 🎁 cpp_03: Inheritance [BONUS]

**Amaç**: Temel ve türetilmiş sınıflar, inheritance'ı öğrenmek.

#### **ex00: ClapTrap**
- **Konu**: Temel sınıf tasarımı
- **Dosyalar**: `ClapTrap.hpp`, `ClapTrap.cpp`, `main.cpp`
- **Sınıf**: `ClapTrap` - Bir robot karakteri simülasyonu
- **Özellikler**:
  - `name`, `hit_points`, `energy_points`, `attack_damage`
  - `attack()`, `takeDamage()`, `beRepaired()`
  - Loglu çıktı

#### **ex01: ScavTrap inherits from ClapTrap**
- **Konu**: Public inheritance, method override
- **Dosyalar**: `ClapTrap.hpp`, `ClapTrap.cpp`, `ScavTrap.hpp`, `ScavTrap.cpp`, `main.cpp`
- **Sınıf**: `ScavTrap` - ClapTrap'tan miras alır
- **Özellikler**:
  - ScavTrap'a özel `attack()`
  - `guardGate()` - kapı koruma modu
  - Farklı hit_points

#### **ex02: FragTrap inherits from ClapTrap**
- **Konu**: Multiple class variation
- **Dosyalar**: `...` ClapTrap, ScavTrap, FragTrap için
- **Sınıf**: `FragTrap` - ClapTrap'tan miras alır
- **Özellikler**:
  - FragTrap'a özel `attack()`
  - `highFivesGuys()` - high five işlemi
  - Farklı hit_points

#### **ex03: DiamondTrap - Multiple Inheritance**
- **Konu**: çoklu inheritance, virtual inheritance
- **Dosyalar**: `ClapTrap.hpp`, `ScavTrap.hpp`, `FragTrap.hpp`, `DiamondTrap.hpp` ve implementations
- **Sınıf**: `DiamondTrap` - ScavTrap ve FragTrap'tan miras alır
- **Özellikler**:
  - Virtual inheritance (ambiguity'yi çözmek için)
  - `whoAmI()` - isim bilgiserini yazdır
  - Tüm parent metodlarını access edebilme

---

### ⭐ cpp_04: Subtype polymorphism, virtual functions, abstract classes [MANDATORY]

**Amaç**: Virtual functions, polymorphism ve abstract classes öğrenmek.

#### **ex00: Virtual Functions - Animal, Cat, Dog**
- **Konu**: Virtual functions, method overriding
- **Dosyalar**: `Animal.hpp`, `Animal.cpp`, `Cat.hpp`, `Cat.cpp`, `Dog.hpp`, `Dog.cpp` + WrongAnimal versiyonları
- **Sınıflar**:
  - `Animal` - Base class, `makeSound()` virtual
  - `Cat` - "Meow" sesleri, `makeSound()` override
  - `Dog` - "Woof" sesleri, `makeSound()` override
  - `WrongAnimal`, `WrongCat`, `WrongDog` - Virtual olmayan versiyonu (karşılaştırma için)
- **Konsept**: Virtual olmayan vs virtual method davranışları

#### **ex01: Deep Copy - Brain allocation**
- **Konu**: Deep copy, pointer member variables, constructor initialization
- **Dosyalar**: `Animal.hpp`, `Cat.hpp`, `Dog.hpp`, `Brain.hpp`, `Brain.cpp` + implementations
- **Sınıf**: `Brain` - 100 adet str fikri saklayan sınıf
- **Özellikler**:
  - `Cat` ve `Dog` her biri dinamik Brain pointer'ı tutar
  - Deep copy constructor ve assignment operator
  - Memory leak olmadığından emin olmak için test etme
- **Array Test**: 100 animal'ın array'ini oluştur

#### **ex02: Pure Virtual Functions - Abstract Animal**
- **Konu**: Abstract classes, pure virtual functions
- **Dosyalar**: Benzer yapı, `Animal` pure virtual yap
- **Değişiklikler**:
  - `Animal` sınıfında `makeSound()` pure virtual
  - `Animal` artık instantiate edilemez
  - `Cat` ve `Dog` tamamlanmış implementasyon gerektirir
- **Konsept**: Arayüz tasarımı, abstract base class pattern

---

## 🛠️ Derleme ve Çalıştırma

Her exercise'in kendi Makefile'ı vardır. Kullanım:

```bash
# Belirli bir dosyaya gitmek
cd cpp_00/ex00

# Derlemek
make

# Programı çalıştırmak
./megaphone "hello world"

# Temizlemek
make clean

# Tamamen temizlemek
make fclean
```

---

## 📚 Öğrenilen Konseptler Özeti

| Modül | Ana Konular | Durum |
|-------|-----------|--------|
| **cpp_04** | Virtual functions, polymorphism, abstract classes | ⭐ **MANDATORY** |
| **cpp_00** | Class basics, namespaces, I/O streams | 🎁 Bonus |
| **cpp_01** | Memory (new/delete), pointers, references, function pointers | 🎁 Bonus |
| **cpp_02** | Operator overloading, OCF (canonical form) | 🎁 Bonus |
| **cpp_03** | Inheritance (single ve multiple), virtual inheritance | 🎁 Bonus |

---

## 🎓 Notlar

- Her proje C++98 standartında yazılmıştır
- Orthodox Canonical Form önemlidir: Default constructor, copy constructor, assignment operator, destructor
- Memory leaks olmamalıdır (valgrind ile test etme)
- const-correctness önemlidir
- Deep copy vs shallow copy dikkat edilmelidir

