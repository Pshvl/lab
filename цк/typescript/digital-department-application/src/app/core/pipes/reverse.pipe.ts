import { Pipe, PipeTransform } from "@angular/core";

@Pipe({
    name: 'reverse',
    pure: false
})
export class ReversePipe implements PipeTransform{
    transform(value: Array<any>, options: {isIncreasingAge: boolean, isNameUppercase: boolean}) {
        console.log(options);
        if (options.isIncreasingAge){
            value=value.map(item => ({...item, age: item.age+1}))
        }

        if(options.isNameUppercase){
            value=value.map(item=>({...item, name: item.name.toUpperCase()}))
        }

        if (!value) return;
        return value.reverse();
    }

}