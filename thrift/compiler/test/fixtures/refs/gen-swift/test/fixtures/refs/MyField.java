/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.refs;

import com.facebook.swift.codec.*;
import com.facebook.swift.codec.ThriftField.Requiredness;
import com.facebook.swift.codec.ThriftField.Recursiveness;
import java.util.*;

import static com.google.common.base.MoreObjects.toStringHelper;

@SwiftGenerated
@ThriftStruct(value="MyField", builder=MyField.Builder.class)
public final class MyField {
    @ThriftConstructor
    public MyField(
        @ThriftField(value=1, name="opt_value", requiredness=Requiredness.OPTIONAL) final Long optValue,
        @ThriftField(value=2, name="value", requiredness=Requiredness.NONE) final long value,
        @ThriftField(value=3, name="req_value", requiredness=Requiredness.REQUIRED) final long reqValue
    ) {
        this.optValue = optValue;
        this.value = value;
        this.reqValue = reqValue;
    }
    
    @ThriftConstructor
    protected MyField() {
      this.optValue = null;
      this.value = 0L;
      this.reqValue = 0L;
    }
    
    public static class Builder {
        private Long optValue;
        @ThriftField(value=1, name="opt_value", requiredness=Requiredness.OPTIONAL)
        public Builder setOptValue(Long optValue) {
            this.optValue = optValue;
            return this;
        }
        private long value;
        @ThriftField(value=2, name="value", requiredness=Requiredness.NONE)
        public Builder setValue(long value) {
            this.value = value;
            return this;
        }
        private long reqValue;
        @ThriftField(value=3, name="req_value", requiredness=Requiredness.REQUIRED)
        public Builder setReqValue(long reqValue) {
            this.reqValue = reqValue;
            return this;
        }
    
        public Builder() { }
        public Builder(MyField other) {
            this.optValue = other.optValue;
            this.value = other.value;
            this.reqValue = other.reqValue;
        }
    
        @ThriftConstructor
        public MyField build() {
            return new MyField (
                this.optValue,
                this.value,
                this.reqValue
            );
        }
    }
    
    private final Long optValue;
    private final long value;
    private final long reqValue;

    
    @ThriftField(value=1, name="opt_value", requiredness=Requiredness.OPTIONAL)
    public Long getOptValue() { return optValue; }
        
    @ThriftField(value=2, name="value", requiredness=Requiredness.NONE)
    public long getValue() { return value; }
        
    @ThriftField(value=3, name="req_value", requiredness=Requiredness.REQUIRED)
    public long getReqValue() { return reqValue; }
    
    @Override
    public String toString() {
        return toStringHelper(this)
            .add("optValue", optValue)
            .add("value", value)
            .add("reqValue", reqValue)
            .toString();
    }
    
    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }
    
        MyField other = (MyField)o;
    
        return
            Objects.equals(optValue, other.optValue) &&
            Objects.equals(value, other.value) &&
            Objects.equals(reqValue, other.reqValue) &&
            true;
    }
    
    @Override
    public int hashCode() {
        return Arrays.deepHashCode(new Object[] {
            optValue,
            value,
            reqValue
        });
    }
    
}
