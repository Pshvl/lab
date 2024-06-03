import { Component } from '@angular/core';
import { FormControl, FormGroup, Validators } from '@angular/forms';
import { Pet } from 'src/app/core/data-classes/pet';

interface PetForm {
  name: FormControl<string>,
  gender: FormControl<string>,
  birthday: FormControl<Date>,
  type: FormControl<string>
}

@Component({
  selector: 'app-form1',
  templateUrl: './form1.component.html',
  styleUrls: ['./form1.component.css']
})
export class Form1Component {

  pets: Pet[] = [
    new Pet("Буся", "Девочка", new Date(2024, 2, 5), "Кошка"),
    new Pet("Шарик", "Мальчик", new Date(2023, 7, 12), "Собака"),
    new Pet("Кнопка", "Девочка", new Date(2024, 0, 18), "Мышь"),
    new Pet("Ингиборга", "Девочка", new Date(2024, 0, 10), "Змея")
  ]

  myForm: FormGroup = new FormGroup<PetForm>({
    name: new FormControl('', { validators: [Validators.required], nonNullable: true, }),
    gender: new FormControl('', { validators: [Validators.required], nonNullable: true }),
    birthday: new FormControl(new Date(), { nonNullable: true }),
    type: new FormControl('', { nonNullable: true })
  })

  constructor() {
  }

  onSubmit() {
    let values=this.myForm.getRawValue();
    if(values.type==''){
      if (values.gender=='Мальчик'){
        values.type="Кот"
      }
      if (values.gender=='Девочка'){
        values.type="Кошка"
      }
    }
    let today=new Date();
    let age=Math.ceil((today.getTime()-new Date(values.birthday).getTime())/(1000 * 3600 * 24));
    this.pets.push(new Pet(
      values.name, 
      values.gender,
      values.birthday,
      values.type));
  }

}
