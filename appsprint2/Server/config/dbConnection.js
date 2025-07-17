import mongoose from "mongoose";

/**
 * @Connects to MongoDB database
 */
mongoose.set('strictQuery', false);

const connectionToDB= async ()=>{

    try {
        const{ connection}= await mongoose.connect(
            process.env.MONGODB_URL||`mongodb://localhost:27017/appLms`
        )
    
        if(connection){
            console.log(`Connected to MongoDB :${connection.host}`);
        }

    } catch (e) {
        console.log(e);
        process.exit(1);
    } 
}
export default connectionToDB;