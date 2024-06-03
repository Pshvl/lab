export class Pet{
    age: number;
    

    constructor(public name: string, public gender:string, public birthday:Date, public type:string ){
        let today=new Date();
       
        this.age=Math.ceil((today.getFullYear()-new Date(birthday).getFullYear())*12+(today.getMonth()-new Date(birthday).getMonth()))
        
        
    }
  }