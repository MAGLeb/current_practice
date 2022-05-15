const person = {
    name: 'Gleb',
    age: 24,
    greet_0: () => console.log(this.name),
    greet_1() {console.log(this.name)},
    greet_2: function() {console.log(this.name)}
}

console.log(person);
person.greet_0();
person.greet_1();
person.greet_2();
