import { Component } from '@angular/core';
import { Kitten } from 'src/app/core/data-classes/kitten';


@Component({
  selector: 'app-form2',
  templateUrl: './form2.component.html',
  styleUrls: ['./form2.component.css']
})
export class Form2Component {

  kittens:Kitten[]=[
    new Kitten("Бусинка", "Девочка", new Date(2024, 2, 5), "Британская"),
    new Kitten("Тёма", "Мальчик", new Date(2023, 7, 12), "Американский керл"),
    new Kitten("Диона", "Девочка", new Date(2024, 0, 18), "Японский бобтейл"),
    new Kitten("Васёк", "Мальчик", new Date(2024, 0, 10), "Мейн-кун"),
    new Kitten("Алина", "Девочка", new Date(2023, 6, 23), "Сибирская"),
  ]

  name:string='';
  gender:string='';
  age:number=0;
  type:string='';

  addKitten(){
    this.kittens.push(new Kitten(this.name, this.gender, new Date(), this.type));
    this.name='';
    this.gender='';
    this.age=0;
    this.type='';
  }

  onNameChange(): void{
    console.log("Имя изменилось на"+ this.name);
  }
}
